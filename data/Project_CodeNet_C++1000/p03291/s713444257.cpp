#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <functional>
#include <map>
#include <queue>
    
#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using TP = tuple<ll, ll, ll>;
ll MOD = 1e9+7;
const int INF = 1000*1000*1000;
const ll LINF = (ll)1e18;
int xv[4] = {-1, 1, 0, 0};
int yv[4] = {0, 0, -1, 1};

ll dp[100002][4];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;
    cin >> S;
    
    REP(i, 100002){
        REP(j,4){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    
    REP(i, S.size()){
        REP(j, 4){
            if(S[i] != '?'){
                dp[i+1][j] += dp[i][j]; dp[i+1][j] %= MOD;
            }
            else{
                dp[i+1][j] += dp[i][j] * 3 % MOD;
            }
        }
        if(S[i] == 'A' || S[i] == '?'){ dp[i+1][1] += dp[i][0]; dp[i+1][1] %= MOD;};
        if(S[i] == 'B' || S[i] == '?'){ dp[i+1][2] += dp[i][1]; dp[i+1][2] %= MOD;};
        if(S[i] == 'C' || S[i] == '?'){ dp[i+1][3] += dp[i][2]; dp[i+1][3] %= MOD;};
    }
    cout << dp[S.size()][3] << endl;
    
    return 0;
}
