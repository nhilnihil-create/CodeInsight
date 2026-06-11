#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define X first
#define Y second
#define sz(v) (int)v.size()

void solve();

main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ONPC
	freopen("in.txt", "r", stdin);
#endif
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

const int N = 2005;
int n, k, q, a[N], ans = 1e9 + 7;

void solve() {
	cin >> n >> k >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		int tek = a[i];
		vector<int> cur, get;
		for (int j = 1; j <= n + 1; ++j) {
			if (j == n + 1 || a[j] < tek) {
				if (sz(cur) == 0) continue;
				sort(cur.begin(), cur.end());
				for (int z = 0; z < sz(cur) - k + 1; ++z) get.pb(cur[z]);
				cur.clear();
			} else cur.pb(a[j]);
		}
		sort(get.begin(), get.end());
		if (sz(get) < q) continue;
		ans = min(ans, get[q - 1] - tek);
	}
	cout << ans;
}