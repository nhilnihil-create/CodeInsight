#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>


using namespace std;


int main() {
	int H, W, TMP;
	cin >> H >> W;

	char tmp;

	vector<vector<int>> N(H + 2, vector<int>(W + 2));
	vector<vector<char>> ans(H, vector<char>(W));

	for (int i = 0; i <= H + 1; i++) {
		for (int j = 0; j <= W + 1; j++) {
			if (i == 0 || j == 0 || i == H + 1 || j == W + 1) {
				N[i][j] = 0;
			}
			else {
				cin >> tmp;
				if (tmp == '.') {
					N[i][j] = 0;
				}
				else {
					N[i][j] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (N[i][j] == 1) {
				ans[i - 1][j - 1] = '#';
			}
			else {
				TMP = 0;
				for (int x = -1; x <= 1; x++) {
					for (int y = -1; y <= 1; y++) {
						TMP += N[i + x][ j + y];
					}
				}
				ans[i - 1][j - 1] = TMP + 48;
			}
		}
	}


	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << ans[i][j];
		}
		cout << "\n";
	}

	return 0;
}
