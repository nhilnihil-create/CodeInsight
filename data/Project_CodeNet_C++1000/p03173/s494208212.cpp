#include<iostream>
using namespace std;
#define ll long long
#define maxx 405
#define inf 1e15+7
ll sum(ll a[],ll i,ll j)
{
    ll s=0;
    for(ll k=i;k<=j;k++)
        s+=a[k];
    return s;
}
ll f(ll a[],ll n,ll dp[][maxx],ll i,ll j)
{
    if(i>=j)
        return 0;
    if(dp[i][j]!=0)
        return dp[i][j];
    dp[i][j]=inf;
    for(ll k=i;k<=j;k++)
    {
        dp[i][j]=min(dp[i][j],f(a,n,dp,i,k)+f(a,n,dp,k+1,j)+sum(a,i,k)+sum(a,k+1,j));
    }
    return dp[i][j];
}
int main()
{
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll dp[maxx][maxx]={0};
    cout<<f(a,n,dp,0,n-1);
}
