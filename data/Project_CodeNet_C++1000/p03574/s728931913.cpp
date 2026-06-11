#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	//string masu[H] = {};
	vector<vector<char>> c ( H, vector<char>(W));
	int m[H][W] = {};
	rep(i, H) {
		rep(j, W) {
			cin >> c[i][j];
		}
	}
	rep(i, H) {
		rep(j, W) {
			if (c[i][j] == '#') {
				for (int dx = -1; dx <= 1; dx++) {
					for (int dy = -1; dy <= 1; dy++) {
						int nx = i + dx;
						int ny = j + dy;
						if (0 <= nx && nx < H && 0 <= ny && ny < W) {
							m[nx][ny]++;
						}
					}
				}
			}
		}
	}

	rep(i, H) {
		rep(j, W) {
			if (c[i][j] == '#') {
				cout << "#";
			}
			else {
				cout << m[i][j];
			}
		}
		cout << endl;
	}
}