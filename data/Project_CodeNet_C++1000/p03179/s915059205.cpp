#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)

using ll = long long;
using namespace std;

const ll MOD = 1000000007;

ll n, dp[4000][4000], sum[4000];
string s;

int main(){
    cin >> n >> s;
    rep(i,n) dp[0][i] = 1; // 先頭を選択し終えた状態
    rep(i,n-1){ //　不等号ごとにDPする
        // 累積和
        rep(j,n-i) sum[j+1] = ( dp[i][j] + sum[j] ) % MOD;
        // DP遷移
        if(s[i] == '>') rep(j,n-1-i) dp[i+1][j] = sum[j+1];
        else rep(j,n-1-i) dp[i+1][j] = ( sum[n-i] - sum[j+1] + MOD) % MOD;
    }
    cout << dp[n-1][0] << endl;
    return 0;
}