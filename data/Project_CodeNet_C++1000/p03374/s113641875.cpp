#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MAXN = 120000;

int n;
ll c;
ll x[MAXN];
ll y[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> c;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	ll ans = 0;
	ll sum = accumulate(y, y + n, 0ll);
	ll mx = 0;
	ll mx2 = 0;
	ll asum = 0;
	for (int i = n - 1; i >= 0; --i) {
		ans = max(ans, sum - x[i] + mx2);
		ans = max(ans, sum - 2 * x[i] + mx);
		sum -= y[i];
		asum += y[i];
		mx = max(mx, asum - (c - x[i]));
		mx2 = max(mx2, asum - 2 * (c - x[i]));
	}
	ans = max(ans, mx);
	cout << ans << "\n";
	return 0;
}


