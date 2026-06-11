#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;

// macros
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define REP1(i,n) for(int i=1;i<((int)n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

ll n;
ll a[16][16];
ll dp[(1 << 16)];

ll rec(ll s) {
	if (dp[s] != -LLINF)
		return dp[s];

	for (ll t = s; t >= 1; t = (t - 1) & s) {
		if (t == s) {
			ll sum = 0;
			REP(i, n) {
				for (ll j = i + 1; j < n; j++) {
					if ((t >> i) & 1 && (t >> j) & 1)
						sum += a[i][j];
				}
			}

			dp[s] = sum;
		}
		else
			dp[s] = max(dp[s], rec(t) + rec(s ^ t));
	}



}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	REP(i, n)REP(j, n)cin >> a[i][j];
	REP(i, (1 << 16))dp[i] = -LLINF;
	dp[0] = 0;

	ll s = (1 << n);
	rec(s-1);

	cout << dp[s - 1] << endl;

}


