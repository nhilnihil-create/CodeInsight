#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int>A(n+1);
    for (int i = 1;i<=n;i++)cin>>A[i];
    vector<vector<int>>dp(n+2,vector<int>(k+1,0));
    for (int i = 0;i<=k;i++){
        if (i>A[1])dp[1][i] = 0;
        else dp[1][i] = 1;
    }
    dp[0][0] = 1;
    for (int i = 2;i<=n;i++){
        for (int j = 0;j<=k;j++){
            if (j==0){dp[i][j] = dp[i-1][j];continue;}
            dp[i][j] = (dp[i][j-1] + dp[i-1][j])%mod;
            if (j>A[i])dp[i][j]-=dp[i-1][j-A[i]-1];
            dp[i][j]%=mod;
            if (dp[i][j]<0)dp[i][j]+=mod;
        }
    }
    cout<<dp[n][k];
    return 0;
}