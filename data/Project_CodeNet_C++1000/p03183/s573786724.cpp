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

struct st {
	ll w, s, v;
};

int n;
st a[1200];

ll dp[20100];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].w >> a[i].s >> a[i].v;
	}
	sort(a, a + n, [] (st a, st b) -> bool {
			return a.s + a.w < b.s + b.w;
			});
	for (int i = 0; i < n; ++i) {
		for (int j = a[i].s; j >= 0; --j)
			dp[j + a[i].w] = max(dp[j + a[i].w], dp[j] + a[i].v);
	}
	ll ans = 0;
	for (int i = 0; i < 20100; ++i)
		ans = max(ans, dp[i]);
	cout << ans << "\n";
	return 0;
}


