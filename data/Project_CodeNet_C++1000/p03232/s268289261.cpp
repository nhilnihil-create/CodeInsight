// In the Name of God

#include <bits/stdc++.h>

using namespace std;

#define	ll long long
#define ull unsigned long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define all(v) v.begin(), v.end()
#define bpc(v) __builtin_popcountll(v)
#define itr iterator
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; --i)
#define ub upper_bound
#define lb lower_bound

const int N = 1e5 + 5;
const ll mod = 1e9 + 7;
const int inf = 1e9 + 1;
const double eps = 1e-15;
const int pw = 257;

int n;
ll a[N], f[N], res, t[N * 4];

void upd(int v, int l, int r, int L, int R, ll val) {
	if (r < L || R < l)
		return;
	if (L <= l && r <= R) {
		t[v] = (t[v] + val) % mod;
		return;
	}
	int mid = (l + r) >> 1;
	upd(v + v, l, mid, L, R, val);
	upd(v + v + 1, mid + 1, r, L, R, val);
}

ll get(int v, int l, int r, int pos) {
	if (l == r) 
		return t[v];
	int mid = (l + r) >> 1;
	if (pos <= mid)
		return (t[v] + get(v + v, l, mid, pos)) % mod;
	else
		return (t[v] + get(v + v + 1, mid + 1, r, pos)) % mod;
}

/*
inline ll calc(int l, int r) {
	ll res = 1;
	rep(i, l, r)
		res = (res * i) % mod;
	return res;
}
*/

ll binpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b % 2 == 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	} 
	return res;
}

int main() {
	#ifdef Madi
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	#endif

	cin >> n;
	rep(i, 1, n)
		cin >> a[i];

	f[0] = 1;
    rep(i, 1, n)
    	f[i] = (f[i - 1] * i) % mod;	

    rep(i, 1, n) {
    	upd(1, 1, n, 1, n - i + 1, f[n] * binpow(i, mod - 2));
    	if (i > 1)
    		upd(1, 1, n, i, n, f[n] * binpow(i, mod - 2));
    }
	/*upd(1, 1, n, 1, n, f[n]);
	rep(d, 1, n - 1) {
		ll ans = 0;
		ll p = 1, q = 0;
		rep(k, 1, d)
			p = (p * k) % mod;
		q = (q + p) % mod;

		rep(k, 1, n - d - 1) {
			p = ((p * binpow(k, mod - 2)) % mod * (k + d)) % mod;
			q = (q + p) % mod;
		}
		ans = (ans + (f[n - d - 1] * q) % mod) % mod;
		cerr << ans << ' ';
		upd(1, 1, n, 1, n - d, ans);
		upd(1, 1, n, d + 1, n, ans);
	}
	*/
	rep(i, 1, n)  {
//		cout << get(1, 1, n, i) << ' ';
		res = (res + (get(1, 1, n, i) * a[i]) % mod) % mod;
	}
//	cout << "\n";

	cout << res;

	#ifdef Madi
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}