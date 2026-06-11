#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD=1e9+7;

int main() {
    string s; cin >> s;
    int n=s.size();
    vector<vector<ll>> dp(n+1, vector<ll>(4, 0));
    dp[0][0]=1;
    for (int i=1; i<=n; ++i) {
        char c=s[i-1];
        dp[i][0]=dp[i-1][0];
        dp[i][1]=dp[i-1][1];
        dp[i][2]=dp[i-1][2];
        dp[i][3]=dp[i-1][3];
        if (c=='A') {
            dp[i][1]+=dp[i-1][0];
        } else if (c=='B') {
            dp[i][2]+=dp[i-1][1];
        } else if (c=='C') {
            dp[i][3]+=dp[i-1][2];
        } else {
            dp[i][0]+=dp[i-1][0]*2;
            dp[i][1]+=dp[i-1][0]+dp[i-1][1]*2;
            dp[i][2]+=dp[i-1][1]+dp[i-1][2]*2;
            dp[i][3]+=dp[i-1][2]+dp[i-1][3]*2;
        }
        for (int k=0; k<4; ++k) {
            dp[i][k]%=MOD;
        }
    }
    cout << dp[n][3];
    return 0;
}