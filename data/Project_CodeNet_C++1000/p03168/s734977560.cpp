#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m;

int main()
{
    cin>>n;
    long double p[n],dp[n+1][n+1];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(j)
                dp[i][j]+=dp[i-1][j-1]*(p[i-1]);
            dp[i][j]+=dp[i-1][j]*(1-p[i-1]);
        }
    }
    long double ans=0;
    for(int i=(n+1)/2;i<=n;i++)
    {
        ans+=dp[n][i];
    }
    cout<<fixed<<setprecision(12)<<ans;
    return 0;
}
