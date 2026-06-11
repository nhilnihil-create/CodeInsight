#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int H, W, N;
	cin >> H >> W >> N;
	vector<vector<int> > G(H + 1);
	G[H].push_back(0);
	for (int i = 0; i < N; ++i) {
		int X, Y;
		cin >> X >> Y;
		if (X >= Y) G[X - 1].push_back(Y - 1);
	}
	for (int i = 0; i <= H; ++i) {
		sort(G[i].begin(), G[i].end());
	}
	int lim = 0, ans = -1;
	for (int i = 0; i < H && ans == -1; ++i) {
		for (int j = G[i].size() - 1; j >= 0; --j) {
			if (lim <= i - G[i][j] && i - G[i][j] <= lim + 1) lim = i - G[i][j] + 1;
		}
		for (int j = 0; j < G[i + 1].size(); ++j) {
			if (i - G[i + 1][j] >= lim) {
				ans = i + 1;
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}