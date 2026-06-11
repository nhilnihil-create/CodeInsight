#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
 
const ll MOD = 1e9+7;
 
int main(){
    ll n; string s; cin >> n >> s;
    vector<vector<ll>> dp(n,vector<ll>(n,1));
    rep(i,n-1){
        // 累積和
        vector<ll> sum(n-i,0);
        rep(j,n-i) sum[j] = dp[i][j];
        rep(j,n-i-1) sum[j+1] += sum[j], sum[j+1] %= MOD;
        // DP遷移
        rep(j,n-i-1){
            if(s[i] == '<') dp[i+1][j] = sum[j] % MOD;
            else dp[i+1][j] = (sum[n-i-1] - sum[j] + MOD) % MOD;
        }
    }
    cout << dp[n-1][0] << endl;
}