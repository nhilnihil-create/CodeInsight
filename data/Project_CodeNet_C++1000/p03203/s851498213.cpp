#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int H, W, n;
	cin >> H >> W >> n;
	vector<vector<int> > all(W + 1);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		all[y].push_back(x);
	}
	for (int i = 1; i <= W; ++i) sort(all[i].begin(), all[i].end()), all[i].push_back(H + 1);
	int x = 1, y = 1, ans = H;
	for (int round = 1; ; ++round) {
		++x;
		int i = lower_bound(all[y].begin(), all[y].end(), x) - all[y].begin();
		ans = min(ans, round + all[y][i] - x);
		if(all[y][i] == x) break;
		if(y < W) {
			++y;
			i = lower_bound(all[y].begin(), all[y].end(), x) - all[y].begin();
			if(all[y][i] == x) --y;
		}
	}
	cout << ans << endl;
	return 0;
}