#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

string S;
ll dp[100010][4];

ll solve(){
    dp[0][0] = 1;
    REP(i, S.length()){
        if(S[i] == '?'){
            REP(j, 4) dp[i + 1][j] = 3 * dp[i][j] % MOD;
        }else{
            REP(j, 4) dp[i + 1][j] = dp[i][j];
        }
        if(S[i] == 'A' || S[i] == '?'){
            dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % MOD;
        }
        if(S[i] == 'B' || S[i] == '?'){
            dp[i + 1][2] = (dp[i + 1][2] + dp[i][1]) % MOD;
        }
        if(S[i] == 'C' || S[i] == '?'){
            dp[i + 1][3] = (dp[i + 1][3] + dp[i][2]) % MOD;
        }
    }
    return dp[S.length()][3];
}

signed main(){
    cin >> S;
    PRINT(solve());
    return 0;
}