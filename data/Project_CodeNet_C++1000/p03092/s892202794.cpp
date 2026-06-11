#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
#include<bitset>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 998244353LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, a, b;
	cin >> n >> a >> b;
	vector<ll> p(n);
	REP(i, n) cin >> p[i];
	vector<vector<ll>> dp(n, vector<ll>(n + 1, INF * INF));
	dp[0][0] = a;
	dp[0][p[0]] = 0;
	FOR(i, 1, n) {
		vector<ll> mn1(n + 1, INF * INF);
		vector<ll> mn2(n + 1, INF * INF);
		REP(j, n + 1) {
			if(j == 0) mn1[j] = dp[i - 1][0];
			else mn1[j] = min(dp[i - 1][j], mn1[j - 1]);
		}
		for(ll j = n; j >= 0; j--) {
			if(j == n) mn2[j] = dp[i - 1][n];
			else mn2[j] = min(dp[i - 1][j], mn2[j + 1]);
		}
		REP(j, n + 1) {
			if(j == 0) {
				dp[i][j] = a + dp[i - 1][j];
			} else if(j == p[i]) {
				dp[i][j] = mn1[j];
			} else if(j < p[i]) {
				dp[i][j] = dp[i - 1][j] + a;
			} else {
				dp[i][j] = dp[i - 1][j] + b;
			}
		}
	}
	ll ans = INF * INF;
	REP(i, n + 1) {
		ans = min(ans, dp[n - 1][i]);
	}
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */
