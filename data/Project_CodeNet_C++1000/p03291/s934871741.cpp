#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,i0,n) for(int i=i0;i<n;++i)

int main()
{
    const ll m = 1e9+7;
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<ll>> dp(n+1, vector<ll>(4, 0));
    dp[0][0] = 1;

    rep(i,n) {
        rep(j,4) dp[i+1][j] = s[i] == '?' ? (3*dp[i][j]) % m : dp[i][j];
        if(s[i] == 'A' || s[i] == '?') dp[i+1][1] = (dp[i+1][1] + dp[i][0]) % m;
        if(s[i] == 'B' || s[i] == '?') dp[i+1][2] = (dp[i+1][2] + dp[i][1]) % m;
        if(s[i] == 'C' || s[i] == '?') dp[i+1][3] = (dp[i+1][3] + dp[i][2]) % m;
    }

    cout << dp[n][3] << endl;
    return 0;
}