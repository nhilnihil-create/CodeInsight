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

const int MAXN = 210000;

int n;
ll a[MAXN];
ll b[MAXN];
ll x[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	ll ans = 0;
	for (int i = 0; i <= 28; ++i) {
		for (int j = 0; j < n; ++j)
			x[j] = a[j] % (1 << (i + 1));
		sort(x, x + n);
		ll cnt = 0;
		for (int j = 0; j < n; ++j) {
			ll cur = b[j] % (1 << (i + 1));
			if (cur >= (1 << i)) {
				cur -= (1 << i);
				int lb = lower_bound(x, x + n, (1 << i) - cur) - x;
				int rb = lower_bound(x, x + n, (1 << (i + 1)) - cur) - x;
				cnt += lb;
				cnt += n - rb;
			}
			else {
				int lb = lower_bound(x, x + n, (1 << i) - cur) - x;
				int rb = lower_bound(x, x + n, (1 << (i + 1)) - cur) - x;
				cnt += rb - lb;
			}
		}
		if (cnt % 2 == 1)
			ans += (1 << i);
	}
	cout << ans << "\n";
	return 0;
}


