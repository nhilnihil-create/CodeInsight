#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 1LL<<60;
/* -- template -- */
const ll MOD = 1e9 + 7;

ll add(ll a, ll b){
    return (a + b)%MOD;
}
int main(){
    string S; cin >> S;
    ll dp[S.size() + 1][4];
    dp[0][0] = 1;
    dp[0][1] = dp[0][2] = dp[0][3] = 0;
    //dp[i + 1][0] : i文字目まで見たときの全ルート数
    //dp[i + 1][1] : i文字目まで見たときのAが登場する数
    //if(S[i] == 'A' || S[i] == '?')dp[i + 1][1] += dp[i][1] + dp[i][0]
    //dp[i + 1][2] : i文字目まで見たときのABが登場する数
    //if(S[i] == 'B' || S[i] == '?')dp[i + 1][2] += dp[i][2] + dp[i][1]
    //dp[i + 1][3] : i文字目まで見たときのABCが登場する数
    //if(S[i] == 'C' || S[i] == '?')dp[i + 1][3] += dp[i][3] + dp[i][2]
    rep(i, S.size()){
        rep(j, 4){
            if(S[i] == '?'){
                dp[i + 1][j] = (3 * dp[i][j]) % MOD;
            }else{
                dp[i + 1][j] = dp[i][j];
            }
        }
        bool flg = (S[i] == '?');
        if(S[i] == 'A' || flg){
            dp[i + 1][1] = (dp[i + 1][1] + dp[i][0])%MOD;
        }
        if(S[i] == 'B' || flg){
            dp[i + 1][2] = (dp[i + 1][2] + dp[i][1])%MOD;
        }
        if(S[i] == 'C' || flg){
            dp[i + 1][3] = (dp[i + 1][3] + dp[i][2])%MOD;
        }
    }
    cout << dp[S.size()][3] << endl;
}
