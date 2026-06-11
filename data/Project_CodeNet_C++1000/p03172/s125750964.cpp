#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    long long mod = 1e9 + 7;
    vector<long long>v(n + 5);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    long long dp[n + 5][k + 5], cum[n + 5][k + 5];
    //sort(v.begin() + 1, v.begin() + n + 1);
    dp[1][0] = 1, cum[1][0] = 1;
    for(int i = 1; i <= v[1]; i++){
        dp[1][i] = 1;
        cum[1][i] = (cum[1][i - 1] + dp[1][i]) % mod;
    }
    for(int i = v[1] + 1; i <= k; i++){
        dp[1][i] = 0;
        cum[1][i] = cum[1][i - 1];
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= v[i]; j++){
            dp[i][j] = cum[i - 1][j];
            if(j == 0){
                cum[i][j] = dp[i][j];
            }
            else{
                cum[i][j] = (cum[i][j - 1] + dp[i][j])%mod;
            }
        }
        for(int j = v[i] + 1; j <= k; j++){
            dp[i][j] = (cum[i - 1][j] - cum[i - 1][j - v[i] - 1] + 2*mod) % mod;
            cum[i][j] = (cum[i][j - 1] + dp[i][j]) % mod;
        }
    }
    cout << dp[n][k];
    return 0;
}