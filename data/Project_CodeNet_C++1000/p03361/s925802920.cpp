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
	vector<vector<char>> board(H+2, vector<char>(W+2, '.'));
	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			cin >> board[h][w];
		}
	}
	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			if (board[h][w] == '#') {
				bool ok = false;
				if (board[h + 1][w] == '#') ok = true;
				if (board[h - 1][w] == '#') ok = true;
				if (board[h][w + 1] == '#') ok = true;
				if (board[h][w - 1] == '#') ok = true;
				if (!ok) {
					print("No");
					return 0;
				}
			}
		}
	}
	print("Yes");
}