#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll dp[n][n+1];
    dp[n-1][1] = s[n-2] == '<';
    dp[n-1][2] = s[n-2] == '>';
    for(int i = n-2; i >= 1; i--) {
        if(s[i-1] == '<') {
            dp[i][n-i+1] = 0;
            for(int k = n-i; k >= 1; k--)
                dp[i][k] = (dp[i][k+1] + dp[i+1][k])%mod;
        }
        else {
            dp[i][1] = 0;
            for(int k = 2; k <= n-i+1; k++)
                dp[i][k] = (dp[i][k-1] + dp[i+1][k-1]) % mod;
        }
    }
    ll ans = 0;
    for(int j = 1; j <= n; ++j)
        ans = (ans + dp[1][j]) % mod;
    cout << (ans+mod) % mod;
    return 0;
}
