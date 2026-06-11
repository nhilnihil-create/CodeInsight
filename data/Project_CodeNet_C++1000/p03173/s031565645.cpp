#include<bits/stdc++.h>
#define inf 1e15
#define ll long long int
#define mod 1000000007
using namespace std;
ll dp[500][500];
ll sum[500][500];
ll mincost(ll a[],ll i,ll j)
{
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll minc=inf;
    for(ll k=i;k<j;k++)
    {
        minc=min(minc,sum[i][j]+mincost(a,i,k)+mincost(a,k+1,j));
    }
    return dp[i][j]=minc;
}
int main()
{
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(i==j)
                sum[i][j]=a[i];
            else
                sum[i][j]=a[j]+sum[i][j-1];
        }
    }
    cout<<mincost(a,1,n)<<endl;
    return 0;
}
