#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(ll i = 0LL; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n-1; i >= 0LL; i--)
#define FOR(i, n, m) for(ll i = n; i < (ll)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18
#define INFD 1e18
#define PI 3.14159265358979
#define MOD 1000000007
#define vl vector<ll>

vector<ll> dx = {-1, 1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


int main()
{
	ll N;
	cin >> N;

	vector<ll> C(N);
	REP(i, N) cin >> C[i];

	vector<ll> c;
	c.push_back(0);
	c.push_back(C[0]);
	REP(i, N-1) {
		if (C[i] != C[i+1]) {
			c.push_back(C[i+1]);
		}
	}
	vector<ll> dp(c.size()+1);
	dp[1] = 1;
	vector<ll> pre(1000000);
	pre[c[1]] = 1;
	// cout << "dp" << endl;
	// REP(j, dp.size()) cout << dp[j] << " ";
	// cout << endl;
	// cout << "pre" << endl;
	// REP(j, 10) cout << pre[j] << " ";
	// cout << endl;
	FOR(i, 2, dp.size()) {
		dp[i] = dp[i-1] + dp[pre[c[i]]];
		dp[i] %= MOD;
		pre[c[i]] = i;
		// cout << "dp" << endl;
		// REP(j, dp.size()) cout << dp[j] << " ";
		// cout << endl;
		// cout << "pre" << endl;
		// REP(j, 10) cout << pre[j] << " ";
		// cout << endl;
	}
	PRINT(dp.back());
	return 0;
}
