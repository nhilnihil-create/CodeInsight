#include<bits/stdc++.h>
using namespace std;
long double a[3000],dp[3000][3000];
long long n;
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long m=n/2;
    if(n%2==0) m--;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dp[i-1][0]*a[i];
       // cout<<dp[i][0]<<" ";
        dp[0][i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[j][i]=dp[j-1][i]*(1-a[j]);
         //   cout<<dp[j][i]<<" ";
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            dp[j][i]=a[j]*dp[j-1][i]+(1-a[j])*dp[j-1][i-1];
        }
    }
    long double ans=0;
    for(int i=0;i<=m;i++)
    {
        ans+=dp[n][i];
    }
    cout<<setprecision(10)<<fixed<<ans<<endl;
    return 0;
}
