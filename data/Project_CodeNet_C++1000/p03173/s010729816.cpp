#include<bits/stdc++.h>
#define ll long long int
using namespace std;



ll slimes(ll i,ll j,ll slime[],ll dp[][400])
{
    if(i>j || i==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    ll sum = LONG_MAX;
    for(ll k=i;k<j;k++)
    {
        ll sum1=0;
        ll sum2=0;
        for(ll q=i;q<=k;q++)
        {
            sum1 = sum1 +slime[q];
        }
        for(ll q=k+1;q<=j;q++)
        {
            sum2 = sum2 +slime[q];
        }
        sum = min(sum,slimes(i,k,slime,dp)+slimes(k+1,j,slime,dp)+sum1+sum2);
    }
    return dp[i][j] = sum;
}

int main()
{
    ll n;
    cin>>n;
    ll slime[n];
    for(ll i=0;i<n;i++)
    {
        cin>>slime[i];
    }
    ll dp[400][400];
    for(ll i=0;i<400;i++)
    {
        for(ll j=0;j<400;j++)
        {
            dp[i][j] = -1;
        }
    }
    cout<<slimes(0,n-1,slime,dp);
}
