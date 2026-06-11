#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define X first
#define Y second
#define sz(v) (int)v.size()
using ord = tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>;

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

const int N = 1e5 + 5;
int n, a[N], fenv[N + N];

void inic() {
	for (int i= 0; i < N + N; ++i) fenv[i] = 0;
}

void inc(int r, int add) {
	for (; r < N + N; r += r & -r) fenv[r] +=add;
}

int get(int r) {
	int res= 0;
	for (; r > 0; r -= r & -r) res += fenv[r];
	return res;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	if (n == 1) {
		cout << a[1] << '\n';
		return;
	}
	ll all = (ll)n * (ll)(n) / (ll)2;
	int lef = 0, rig = 1e9 + 1;
	while (rig - lef > 1) {
		int mid = (lef + rig) / 2;
		ll cur = 0;
		inic();
		inc(N, 1);
		int bal = 0;
		for (int i = 1; i <= n; ++i) {
			int x = a[i];
			if (x >= mid) x = 1;
			else x = -1;
			bal += x;
			cur += get(N + bal);
			inc(N + bal, 1);
		}
		if (cur * 2 >= all) {
			lef = mid;
		} else {
			rig = mid;
		}
	}
	cout << lef << '\n';
}