#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e6 + 10;
int AA[mxn];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int x;
			cin >> x;
			x--;
			AA[x] |= 1 << i;
		}
	}
	int need = 0;
	for (int i = 0; i < m; ++i) {
		int v;
		cin >> v;
		if (v == 1)
			need |= 1 << i;
	}
	int ans = 0;
	for (int i = 0; i < (1 << n); ++i) {
		int now = 0;
		for (int j = 0; j < n; ++j) {
			if ((i >> j) & 1)
				now ^= AA[j];
		}
		if (now == need)
			ans++;
	}
	cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
//	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve();
	}
	return 0;
}
