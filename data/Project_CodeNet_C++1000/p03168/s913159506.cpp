#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long double dp[3005][3005];
    long double arr[3005];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    dp[1][1]=arr[1];
    dp[1][0]=(1-arr[1]);
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=(dp[i-1][0]*(1-arr[i]));
        for(int j=1;j<=i;j++)
            dp[i][j]=(dp[i-1][j]*(1-arr[i])) + (dp[i-1][j-1]*arr[i]);
        dp[i][i+1]=0;
    }
    long double ans=0;
    for(int i=(n/2)+1;i<=n;i++)
        ans+=dp[n][i];
    std::cout << std::setprecision(10) << ans;

}
