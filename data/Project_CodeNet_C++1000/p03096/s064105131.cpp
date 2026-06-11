#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
int dp[200010];

int prev1[200010];
int prev2[200010];

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int C[200010];
    rep(i, N) cin >> C[i];
    rep(i, N) {
        if(prev1[C[i]] != 0) prev2[i] = prev1[C[i]];
        prev1[C[i]] = i + 1;
    }
    dp[0] = 1;
    // rep(i, N) cout << prev2[i] << " ";
    // cout << endl;
    rep(i, N) {
        if(prev2[i] != 0 && prev2[i] != i)
            dp[i + 1] += dp[prev2[i]];
        dp[i + 1] += dp[i];
        dp[i + 1] %= mod;
    }
    // rep(i, N + 1) cout << dp[i] << " ";
    // cout << endl;
    cout << dp[N] << endl;

    return 0;
}
// 3 1 4 3 1 3
// 3 3 3 3 1 3
// 3 1 1 1 1 3
// 3 1 4 3 3 3
// 3 3 3 3 3 3

// 1 2 1 2 3 2