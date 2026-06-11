#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007


int main()
{
    ll n,m,i,j;
    cin>>n>>m;
    char a[n+1][m+1];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    ll dp[n+1][m+1];
    dp[1][1]=1;
    ll f=0;
    for(i=1;i<=m;i++)
    {
        if(a[1][i]=='#')
        {
            f=1;
        }
        if(f==0)
        {
            dp[1][i]=1;
        }
        else
        {
            dp[1][i]=0;
        }
    }
    f=0;
    for(i=1;i<=n;i++)
    {
        if(a[i][1]=='#')
        {
            f=1;
        }
        if(f==0)
        {
            dp[i][1]=1;
        }
        else
        {
            dp[i][1]=0;
        }
    }
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=m;j++)
        {
            if(a[i][j]=='#')
            {
                dp[i][j]=0;
            }
            else
            {
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
    }
    cout<<dp[n][m]<<"\n";
}