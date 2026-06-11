#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

const int32 MAX_N = 1002;

int64 dp[MAX_N+1][MAX_N+1][2][2][2];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int32 n,m;
    cin >> n >> m;
    REP(i,n+1)REP(j,m+1)REP(a,2)REP(b,2)REP(c,2){
        if(j == 0)continue;
        dp[i][j][a][b][c] = -LLINF;
    }
    REP(i,n){
        int64 x,y,z;
        cin >> x >> y >> z;
        REP(j,m){
            for(int32 mask = 0; mask < (1 << 3); mask++){
                dp[i+1][j+1][mask>>0&1][mask>>1&1][mask>>2&1]
                 = max(dp[i][j+1][mask>>0&1][mask>>1&1][mask>>2&1],
                        dp[i][j][mask>>0&1][mask>>1&1][mask>>2&1]
                        + x * ((mask>>0&1)?1:-1)
                        + y * ((mask>>1&1)?1:-1)
                        + z * ((mask>>2&1)?1:-1));
            }
        }
    }
    // REP(i,n+1){
    //     REP(j,m+1){
    //         cout << dp[i][j][0][0][0] << " ";
    //     }
    //     cout << endl;
    // }
    int64 ans = 0;
    for(int32 mask = 0; mask < (1 << 3); mask++){
        ans = max(ans, dp[n][m][mask>>0&1][mask>>1&1][mask>>2&1]);
    }
    ANS(ans);
    return 0;
}