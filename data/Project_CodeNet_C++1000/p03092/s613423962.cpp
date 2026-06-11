#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline int msbp(int x) {return 31-__builtin_clz(x);}
inline int msb(int x) {return 1 << msbp(x);}
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
// const int INF = 0x3f3f3f3f;
// const int INF = INT_MAX;
// const int nINF = INT_MIN;
// const ll INF = LLONG_MAX;
// const ll nINF = LLONG_MIN;

/////////////////////////////////////////////////////////////////////

const int N = 5e3+10;

int n, p[N], id[N];
ll dp[N][N], a, b;
// dp[i][j] - min cost to sort elts 1..i and leave elt i at [j-1, j)
// dp[i][j] = (min(dp[i-1][k]), k <= j) + (a when j <= id[i], 0 when j == id[i]-1, b when j > id[i])

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    memset(dp, INF, sizeof(dp));
    cin >> n >> a >> b;
    REP(i, n) {
    	cin >> p[i];
    	id[p[i]] = i;
    }
    FOR(i, 0, n) dp[0][i] = 0;
    FOR(i, 1, n) {
    	ll mn = INF;
    	int cur_id = id[i];
    	FOR(j, 0, n) {
    		mn = min(mn, dp[i-1][j]);
    		ll cost;
    		if(cur_id == j-1) cost = 0;
    		else if(cur_id > j-1) cost = b;
    		else cost = a;
    		dp[i][j] = mn+cost;
    	}
    }
    ll ans = INF;
    FOR(i, 0, n) ans = min(ans, dp[n][i]);
    cout << ans << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE) CHECK IF IT SHOULD BE 2*N!!!!
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - negative arithmetic, ceiling division, modulo (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting max to 0 instead of -INF/min to 0 instead of INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
// - round announcements (WA)
// - multiset::erase (WA)
// - forgetting to rename recursive call when copy/pasting recursive function (WA)
// - not clearing DS between test cases EVEN FOR INPUT (WA, RTE, TLE, MLE)
