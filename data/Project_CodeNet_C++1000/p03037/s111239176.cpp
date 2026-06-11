#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(ii, jj, ll, ss) for(int ii = jj; ii < ll; ii += ss)

int n, m;
set <int> s;
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	int lo = 0, hi = 100000;
	rep(i, 0, m, 1) {
		int l, r;
		cin >> l >> r;
		lo = max(l, lo);
		hi = min(r, hi);
	}
	int ans = hi - lo + 1;
	cout << max(0ll, ans);
}