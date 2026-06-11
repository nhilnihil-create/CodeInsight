///=======================///
/// coder: Andy - Tohrumi ///
///=======================///

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fastio ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define mod 998244353
#define INF LLONG_MAX
#define pb push_back
#define mp make_pair
#define endl '\n'
#define rep(i, s, n) for(int i = s; i < n; i++)
#define Rep(i, n, s) for(int i = n; i > s; i--)
#define repl(i, s, n) for(ll i = s; i < n; i++)
#define Repl(i, n, s) for(ll i = n; i > s; i--)
#define x first
#define y second
using namespace std;
typedef pair<ll, ll> pll;	typedef pair<int, int> ii;
typedef vector<pll> vll;	typedef vector<string> vs;		typedef vector<ii> vii;
typedef vector<int> vi; 	typedef vector<ll> vl;

ll factorial[300005];

void cal() {
	factorial[0] = 1;
	rep(i, 1, 300005) {
		factorial[i] = (factorial[i - 1] * i) % mod;
	}
}

ll binpow(ll a, ll b) {
	if(b == 0) return 1;
	ll x = binpow(a, b >> 1);
	x *= x; x %= mod;
	if(b % 2) return (x * a) % mod;
	else return x;
}

ll bindiv(ll a, ll b) {
	ll inv = binpow(b, mod - 2);
	return (a * inv) % mod;
}

ll C(ll k, ll n) {
	ll x = (factorial[k] * factorial[n - k]) % mod;
	return bindiv(factorial[n], x);
}

signed main() {
	fastio;
	cal();
	ll n, a, b, k; cin >> n >> a >> b >> k;
	vll ans;
	rep(i, 0, n + 1) {
		ll c = k - a * i;
		c /= b;
		if(c <= n && c >= 0 && a * i + b * c == k) {
			ans.pb(mp(i, c));
		}
	}
	ll res = 0;
	rep(i, 0, ans.size()) {
		res = (res + C(ans[i].x, n) * C(ans[i].y, n)) % mod;
	}
	cout << res << endl;
	return 0;
}
