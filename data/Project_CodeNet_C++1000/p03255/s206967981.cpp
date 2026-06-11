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

int n;
ll x;
ll dp[210000];
ll a[210000];
ll ps[210000];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> x;
	ps[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		ps[i + 1] = ps[i] + a[i];
	}
	ll ans = 1e18;
	ll cur = 0;
	for (int i = 1; i <= n; ++i) {
		cur += 5 * a[n - i] + x;
		ll now = cur;
		int cc = 2;
		for (int j = n - 1 - i; j >= 0; j -= i, ++cc) {
			now += (ps[j + 1] - ps[max(0, j - i + 1)]) * (2 * cc + 1);
			if (now > ans)
				break;
		}
		ans = min(ans, now);
	}
	cout << ans + n * x << "\n";
	return 0;
}


