#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    ll n,m;
    cin>>n>>m;
    char arr[n][m];
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            cin>>arr[i][j];
    ll dp[n][m];
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            dp[i][j]=0;
    for(ll i=0;i<n;i++)
    {
        if(arr[i][0]=='#')
            break;
        else
            dp[i][0]=1;
    }
    for(ll i=0;i<m;i++)
    {
        if(arr[0][i]=='#')
            break;
        else
            dp[0][i]=1;
    }
    // for(ll i=0;i<n;i++)
    // {
    //     for(ll j=0;j<m;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    for(ll i=1;i<n;i++)
        for(ll j=1;j<m;j++)
            if(arr[i][j]=='.')
                dp[i][j]=((dp[i-1][j])%mod+(dp[i][j-1])%mod)%mod;
    cout<<dp[n-1][m-1]<<"\n";
}
