#include "bits/stdc++.h"
using namespace std;

const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,-1,0,1 };

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	for (int n = 0; n < H; ++n) {
		cin >> S[n];
	}
	for (int n = 0; n < H; ++n) {
		for (int m = 0; m < W; ++m) {
			if ('#' == S[n][m]) {
				bool b = false;
				for (int l = 0; l < 4; ++l) {
					int x1 = n + dx[l];
					int y1 = m + dy[l];
					if ((0 <= x1) && (H > x1) && (0 <= y1) && (W > y1)) {
						if ('#' == S[x1][y1]) {
							b = true;
						}
					}
				}
				if (!b) {
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}