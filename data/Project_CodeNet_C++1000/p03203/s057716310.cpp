#include <bits/stdc++.h>
using namespace std;

vector<int> obj[200010];
int main() {
	int h, w, n; cin >> w >> h >> n;
	for(int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		--x, --y;
		if(y > x) continue;
		obj[y].push_back(x);
	}
	for(int i = 0; i < h; ++i) {
		obj[i].push_back(w);
		sort(obj[i].begin(), obj[i].end());
	}
	for(int i = 0; i < w; ++i) {
		obj[h].push_back(i);
	}
	int y = 0, x = 0;
	int ans = 1e9, now = 0;
	while(true) {
		int r = *lower_bound(obj[y].begin(), obj[y].end(), x + 1) - x;
		ans = min(ans, now + r);
		if(r == 1) break;
		++x, ++now;
		int d = *lower_bound(obj[y + 1].begin(), obj[y + 1].end(), x);
		if(x != d) {
			++y;
		}
	}
	cout << ans << '\n';
	return 0;
}