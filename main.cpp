//
//  main.cpp
//  Sudoku
//
//  Created by Sohil Ramachandra on 8/14/22.
//

#include <iostream>
#include <vector>
#include "xcode_redirect.hpp"

using namespace std;

void getBoard(vector<vector<char> > &board){
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board[0].size(); j++){
			cin >> board[i][j];
		}
	}
}

void printBoard(vector<vector<char> > &board){
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board[0].size(); j++){
			if (board[i][j] != '*'){
				cout << board[i][j];
			}
			else {
				cout << ' ';
			}
			if (j != 8){
				cout << ' ' << '|' << ' ';
			}
			else {
				cout << '\n';
			}
		}
	}
}

bool isPossible(vector<vector<char> > &board, int r, int c, char num){
	for (int i = 0; i < board[0].size(); i++){
		if (board[r][i] == num){
			return false;
		}
	}
	for (int i = 0; i < board.size(); i++){
		if (board[i][c] == num){
			return false;
		}
	}
	int row = (r / 3) * 3;
	int col = (c / 3) * 3;
	for (int i = row; i < row + 3; i++){
		for (int j = col; j < col + 3; j++){
			if (board[i][j] == num){
				return false;
			}
		}
	}
	return true;
}

void dfs (vector<vector<char> > &board, bool &isFull){
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board[0].size(); j++){
			if (board[i][j] == '*'){
				for (int k = 1; k <= 9; k++){
					if (isPossible(board, i, j, '0' + k)){
						board[i][j] = '0' + k;
						dfs(board, isFull);
						if (isFull){
							return;
						}
						board[i][j] = '*';
					}
				}
				return;
			}
		}
	}
	isFull = true;
}

int main(int argc, char *argv[]){
	
	ios_base::sync_with_stdio(false);
	xcode_redirect(argc, argv);
	
	vector<vector<char> > board (9, vector<char>(9));
	cout << "Enter 9x9 board with an asterisk (*) representing blank squares" << '\n';
	getBoard(board);
	cout << "Before solving: " << '\n';
	printBoard(board);
	
	bool full = false;
	dfs(board, full);
	if (!full){
		cout << "Board cannot be solved :(" << '\n';
	}
	else {
		cout << "After solving: " << '\n';
		printBoard(board);
	}
}
