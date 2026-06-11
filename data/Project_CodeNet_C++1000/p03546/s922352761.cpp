#include "bits/stdc++.h"
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<int>> data(10, vector<int>(10));
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> data[i][j];
		}
	}
	//わーしゃるふろいど
	for (int k = 0; k < 10; ++k) {
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				data[i][j] = min(data[i][j], data[i][k] + data[k][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			int num;
			cin >> num;
			if (-1 != num) {
				ans += data[num][1];
			}
		}
	}
	cout << ans << endl;
	return 0;
}