#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;

int main() {
	int N, C;
	cin >> N >> C;

	VVI d(C, VI(C, 0));

	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			cin >> d[i][j];
		}
	}

	VVI colors(3, VI(C, 0));
	int color;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> color;
			color--;
			colors[(i+j)%3][color]++;
		}
	}

	long long ans = 1e18;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			for (int k = 0; k < C; k++) {
				if (i == j || j == k || k == i) {
					continue;
				}

				vector<int> to = {i, j, k};

				long long tmp = 0;
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < C; y++) {
						tmp += d[y][to[x]] * colors[x][y];
					}
				}
				// printf("ijk %d %d %d: %lld\n", i, j, k, tmp);
				ans = min(ans, tmp);
			}
		}
	}

	cout << ans << endl;
	return 0;
}
