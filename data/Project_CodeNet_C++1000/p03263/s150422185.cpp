#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll test[501][501];
signed main() {
	ll n, m, a = 0, b = 0, c = 0, cn = 0, cnt = 0, ans = 0; cin >> n >> m;
	for (int h = 1; h <= n; h++) {
		for (int i = 1; i <= m; i++) {
			cin >> test[h][i];
			if (test[h][i] % 2 == 1) { c++; }
		}
	}
	if (c % 2 == 1) { c--; }
	for (int h = 1; h <= n; h++) {
		if (h % 2 == 1) {
			for (int i = 1; i <= m; i++) {
				if (cn == c) { break; }
				if (cnt == 0 && test[h][i] % 2 == 1) {
					cnt++; a = h; b = i; cn++;
				}
				else if (cnt == 1 && test[h][i] % 2 == 1) {
					cnt = 0; cn++;
				}
			}
		}
		else {
			for (int i = m; i >= 1; i--) {
				if (cn == c) { break; }
				if (cnt == 0 && test[h][i] % 2 == 1) {
					cnt++; a = h; b = i; cn++;
				}
				else if (cnt == 1 && test[h][i] % 2 == 1) {
					cnt = 0; cn++;
				}
			}
		}
	}
	cnt = 0; cn = 0;
	for (int h = 1; h <= n; h++) {
		if (h % 2 == 1) {
			for (int i = 1; i <= m; i++) {
				if (cn == c) { break; }
				if (cnt == 0 && test[h][i] % 2 == 1) {
					cnt++; cn++;
				}
				else if (cnt == 1 && test[h][i] % 2 == 1) {
					cnt = 0; cn++;
				}
				if (cnt == 1) { ans++; }
			}
		}
		else {
			for (int i = m; i >= 1; i--) {
				if (cn == c) { break; }
				if (cnt == 0 && test[h][i] % 2 == 1) {
					cnt++; cn++;
				}
				else if (cnt == 1 && test[h][i] % 2 == 1) {
					cnt = 0; cn++;
				}
				if (cnt == 1) { ans++; }
			}
		}
	}
	cout << ans << endl; cnt = 0; cn = 0;
	for (int h = 1; h <= n; h++) {
		if (h % 2 == 1) {
			for (int i = 1; i <= m; i++) {
				if (cn == c) { break; }
				if (cnt == 0 && test[h][i] % 2 == 1) {
					cnt++; cn++;
				}
				else if (cnt == 1 && test[h][i] % 2 == 1) {
					cnt = 0; cn++;
				}
				if (cnt == 1) {
					if (i == m) { cout << h << ' ' << i << ' ' << h + 1 << ' ' << i << endl; }
					else { cout << h << ' ' << i << ' ' << h << ' ' << i + 1 << endl; }
					ans++;
				}
			}
		}
		else {
			for (int i = m; i >= 1; i--) {
				if (cn == c) { break; }
				if (cnt == 0 && test[h][i] % 2 == 1) {
					cnt++; cn++;
				}
				else if (cnt == 1 && test[h][i] % 2 == 1) {
					cnt = 0; cn++;
				}
				if (cnt == 1) {
					if (i == 1) { cout << h << ' ' << i << ' ' << h + 1 << ' ' << i << endl; }
					else { cout << h << ' ' << i << ' ' << h << ' ' << i - 1 << endl; }
					ans++;
				}
			}
		}
	}
	return 0;
}