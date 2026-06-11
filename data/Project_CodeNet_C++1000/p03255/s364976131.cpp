#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <limits>
using namespace std;
#define int long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = (((1<<30)-1)<<1)+1;
const int nINF = 1<<31;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

/////////////////////////////////////////////////////////////////////

const int N = 2e5+10;
int n, x, a[N], s[N];

int rangesum(int l, int r) {
	return s[r] - (l > 0 ? s[l-1] : 0);
}

signed main() {
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);
    cin >> n >> x;
    REP(i, n) cin >> a[i];
    s[0] = a[0];
    FOR(i, 1, n-1) s[i] = s[i-1]+a[i];
    int ans = numeric_limits<int>::max();
    FOR(trips, 1, (n+1)/2) {
    	int m = 5;
    	int cur = m*rangesum(n-2*trips, n-1);
    	int idx = n-2*trips;
    	while(idx > 0) {
    		m += 2;
    		cur += m*rangesum(idx-trips, idx-1);
    		idx = idx-trips;
    	}
    	cur += (n+trips)*x;
    	if(cur > 0) ans = min(ans, cur);
    }
    cout << ans << endl;

    return 0;
}

// Easy things to check:
// - LONG LONGS (WA)
// - const int N is correct (WA, RTE)
// - .size()-k underflow (WA, RTE, TLE)
// - small n edge cases (WA)

// Rare mistakes made in the past:
// - division by 0 (WA)
// - integer division (WA)
// - setprecision (WA)
// - INF not big enough using ll (WA)
// - setting min to 0 instead of -INF (WA)
// - outputting debug (WA)
// - allocating too much memory (locRTE, MLE)
// - stack size (locRTE)
