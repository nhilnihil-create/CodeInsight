#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

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

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int q;
	cin >> q;
	while (q--) {
		ll a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		ll ans = 2 * (a - 1);
		ll l = 0;
		ll r = b - a + 1;
		while (r - l > 1) {
			ll mid = (l + r) >> 1;
			ll x = a;
			ll y = a + mid;
			ll x1 = (x + y) / 2;
			ll y1 = (x + y) - x1;
			if (x1 * y1 < a * b)
				l = mid;
			else
				r = mid;
		}
		ans += l;
		cout << ans << "\n";
	}
	return 0;
}

