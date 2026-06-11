#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> board(H + 2, vector<char>(W + 2, '.'));
	for (int h = 1; h <= H; h++) {
		string str;
		cin >> str;
		for (int w = 1; w <= W; w++) {
			board[h][w] = str[w - 1];
		}
	}
	
	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			if (board[h][w] == '.') {
				int n = 0;
				for (int i = -1; i <= 1; i++) {
					for (int j = -1; j <= 1; j++) {
						if (board[h + i][w + j] == '#') n++;
					}
				}
				cout << n;
			}
			else cout << '#';
		}
		cout << endl;
	}

}