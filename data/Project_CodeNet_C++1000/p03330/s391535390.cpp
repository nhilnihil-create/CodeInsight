#include <iostream>
#include <vector>
using namespace std;
const int C_MAX = 30;
const int D_MAX = 1000;
const int INF = 1100000000;

int main() {
	int n, c;
	cin >> n >> c;
	int D[C_MAX][C_MAX];
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			cin >> D[i][j];
		}
	}
	int v[3][C_MAX] = {{0}};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int c;
			cin >> c;
			c--;
			v[(i+j)%3][c]++;
		}
	}
	long long ans = INF;
	for (int c0 = 0; c0 < c; c0++) {
		for (int c1 = 0; c1 < c; c1++) {
			for (int c2 = 0; c2 < c; c2++) {
				if (c0 == c1 || c1 == c2 || c0 == c2) continue;
				long long now = 0;
				vector<int> colors = {c0, c1, c2};
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < c; j++) {
						now += v[i][j] * D[j][colors[i]];
					}
				}
				ans = min(ans, now);
			}
		}
	}
	cout << ans << endl;
	return 0;
}