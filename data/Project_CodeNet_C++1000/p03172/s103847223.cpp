#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    ll dp[n+2][k+2];
    memset(dp,0,sizeof(dp));
    for(ll j=0;j<=k;j++)
    {
        if(j<=a[1])
        dp[1][j]=1;
        else
            dp[1][j]=0;
    }
    for(ll i=2;i<=n;i++)
    {
        for(ll j=0;j<=k;j++)
        {
            if(j==0)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                if((j-1-a[i])>=0)
                    dp[i][j]=(mod+((dp[i][j-1]+dp[i-1][j])%mod)-dp[i-1][j-1-a[i]])%mod;
                else
                    dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
            }
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}
