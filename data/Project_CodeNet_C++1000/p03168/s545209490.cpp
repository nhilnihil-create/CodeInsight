#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
#define deb(x)     cout << #x << " = "<<x<<endl

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)

int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 200005;


ll gcd(ll  a , ll b) {
	return (b == 0) ? a : gcd(b, a % b);
}
ll binpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
ll powmod(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
ll modinv(ll n, ll p)
{
	return powmod(n, MOD - 2, MOD);
}
void max_self(ll &a, ll b) {
	a = max(a, b);
}


int main(int argc, char const *argv[])
{
	// two magical lines to speed up IO
	cin.tie(0);
	ios_base::sync_with_stdio(false);
// #ifndef ONLINE_JUDGE
// 	freopen("in.txt", "r", stdin);
// 	freopen("out.txt", "w", stdout);
// #endif
	int n;
	cin >> n;
	vector <double> dp(n + 1, 0);
	dp[0] = 1;
	F0R(i, n) {
		double p;
		cin >> p;
		for (int j = i + 1; j >= 0; j--) {
			dp[j] = (j > 0 ? dp[j - 1] * p : 0 ) + dp[j] * (1 - p);
		}


	}
	double ans = 0;
	for (int h = n / 2 + 1; h <= n; h++) {
		ans += dp[h];
	}
	cout << fixed << setprecision(17) << ans << endl;
	return 0;

}



