#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll, ll>
#define vl vector<ll>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define N 100005
ll dp[100005][5];

int main()
{
    ll n;cin>>n;
    ll a[n][3];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    for(ll i=0;i<3;i++)
    dp[0][i]=a[0][i];
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<3;j++)
        {
            if(j==0)
            dp[i][j]=a[i][j]+max(dp[i-1][j+1],dp[i-1][j+2]);
            else if(j==1)
            dp[i][j]=a[i][j]+max(dp[i-1][j-1],dp[i-1][j+1]);
            else if(j==2)
            dp[i][j]=a[i][j]+max(dp[i-1][j-1],dp[i-1][j-2]);
        }
    }
    ll mx=0;
    for(ll i=0;i<3;i++)
    mx=max(mx,dp[n-1][i]);
    cout<<mx<<"\n";
}   