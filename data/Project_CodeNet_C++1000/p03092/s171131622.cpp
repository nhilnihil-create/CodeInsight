#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<math.h>
#include<list>
#include<complex>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vvvll vector<vector<vector<ll>>>
#define vtype(type) vector<type>
#define vvtype(type) vector<vector<type>>
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;
struct wall
{
	long long r; ll c;
	bool operator<(const wall& rhs) const {
		if (r != rhs.r) {
			return r < rhs.r;
		}
		else {
			return c < rhs.c;
		}
	}
};


ll const MOD = 1e9 + 7;


ll mod_p(ll x, ll y) {
	x %= MOD;
	y %= MOD;
	return (x + y + MOD) % MOD;
}

ll mod_m(ll x, ll y) {
	x %= MOD;
	y %= MOD;
	return x * y%MOD;
}

ll mod_pow(ll x, ll t) {
	x %= MOD;
	if (t == 0) {
		return 1;
	}
	else {
		ll v = mod_pow(x, t / 2);
		if (t % 2 == 0) {
			return v * v % MOD;
		}
		else {
			return v * v%MOD * x %MOD;
		}
	}
}

ll mod_inv(ll x) {
	return mod_pow(x, MOD - 2);
}

ll const MAX = 5e3 + 5;
vvll dp(MAX, vll(MAX, 1e17));
vll p(MAX);

int main() {
	ll n;
	cin >> n;
	ll a, b;
	cin >> a >> b;
	REP(i, 1, n) {
		cin >> p[i];
	}
	dp[0][0] = 0;
	REP(i, 1, n) {
		REP(j, 0, n) {
			if (j < p[i]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + a);
				dp[i][p[i]] = min(dp[i][p[i]], dp[i - 1][j]);
			}
			else if (j >= p[i]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + b);
			}
		}
	}
	ll ans = 1e17;
	REP(j, 1, n) {
		ans = min(dp[n][j], ans);
	}
	cout << ans << endl;
}