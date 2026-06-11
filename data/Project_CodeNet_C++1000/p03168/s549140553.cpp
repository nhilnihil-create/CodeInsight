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

double dp[3010][3010];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    double p[3010];
    rep(i, N) cin >> p[i];
    dp[0][0] = 1.0;
    rep(i, N) {
        rep(j, i + 1) {
            dp[i + 1][j + 1] += dp[i][j] * p[i];
            dp[i + 1][j] += dp[i][j] * (1.0 - p[i]);
        }
    }

    double ans = 0.0;
    REP(i, (N + 1) / 2, N) {
        ans += dp[N][i];
    }
    cout << fixed << setprecision(12) << ans << endl;


    return 0;
}
