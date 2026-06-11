#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int M = 1e5+10;
int dp[105][M];
int main(){
    int n,k,a;
    cin >> n >> k;
    fill(dp[0],dp[0]+M,1);
    for(int i = 1; i <= n; ++i){
        cin >> a;
        for(int j = 0; j <= k; ++j){
            int r = j;
            int l = max(j-a,0);
            dp[i][j] = dp[i-1][r] - (l ? dp[i-1][l-1] : 0);
            if(dp[i][j] < 0)dp[i][j] += mod;
        }
        if(i != n){
            for(int j = 1; j <= k; ++j){
                dp[i][j] += dp[i][j-1];
                if(dp[i][j] >= mod)dp[i][j]-=mod;
            }
        }
    }
    cout << dp[n][k];
    return 0;
}