#include<bits/stdc++.h>
using namespace std;
using ll=long long int;

int main()
{
    ll n;
    cin>>n;
    vector<ll> pref(n+1);
    vector<ll> a(n+1);
    vector<vector<ll> > dp(n+1,vector<ll> (n+1,0));
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    for(ll i=0;i<=n;i++)
    {
        dp[i][i]=0;
    }
    for(ll i=n;i>=1;i--)
    {
        for(ll j=i+1;j<=n;j++)
        {
            dp[i][j]=min(dp[i+1][j],dp[i][j-1])+pref[j]-pref[i-1];
            for(ll k=i+1;k<j;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+pref[j]-pref[i-1]);
            }
           
        }
    }
    cout<<dp[1][n]<<endl;
}