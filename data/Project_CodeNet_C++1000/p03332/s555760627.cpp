# include <bits/stdc++.h>

using namespace std;
#define _USE_MATH_DEFINES_
#define ll long long
#define ld long double
#define Accepted 0
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define every(x) x.begin(),x.end()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define For(i,x,y)  for (ll i = x; i <= y; i ++) 
#define FOr(i,x,y)  for (ll i = x; i >= y; i --)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// ROAD to...                                                                                                                                                                                                                Red

inline void Input_Output () {
	//freopen(".in", "r", stdin);
   //freopen(".out", "w", stdout);
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 998244353;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

ll n, a, b, k;
ll f[N];
ll rn[N];
ll inv[N];
ll left[N];

ll C(int n, int k) {
	if (k > n) return 0;
	return (f[n] * inv[k] % mod) * inv[n-k] % mod; 
}

ll bpow (ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return res;
}

int main () {
	SpeedForce;

	cin >> n >> a >> b >> k;

	f[0] = 1;
	rn[1] = 1;
	inv[0] = 1;
	f[1] = inv[1] = 1;
	for (int i = 2; i <= n; ++ i)
		rn[i] = mod - (mod / i * rn[mod % i]) % mod;
		
	for (int i = 2; i <= n; ++ i) {
		f[i] = f[i-1] * i % mod;
		inv[i] = inv[i-1] * rn[i] % mod;
	}

	ll res = 0;
	for (int i = 0; i <= n; i ++) if (k >= a * i && (k - a * i) % b == 0) {
		ll j = (k - a * i) / b;
		if (j <= n) {
			res = (res + C(n, j) * C(n, i) % mod) % mod;
		}
	}
	cout << res << '\n';


   	return Accepted;
}

// B...a