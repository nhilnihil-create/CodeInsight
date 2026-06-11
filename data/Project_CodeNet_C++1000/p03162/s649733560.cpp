#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll maxm;
ll dp[100001][3];
int fn(ll a[][3],ll n)
{
    for(ll j=0; j<=2; j++)
    {
        dp[0][j] = a[0][j];
    }
    
    for(ll i=1; i<n; i++)
    {
        dp[i][0] = a[i][0] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = a[i][1] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = a[i][2] + max(dp[i-1][0],dp[i-1][1]);
    }
    return 0;
}
int main()
{
    ll i,j,n;
    cin>>n;
    ll a[n][3];
    for(i=0; i<n; i++)
    {
        for(j=0; j<3; j++)
        {
            cin>>a[i][j];
        }
    }
    fn(a,n);
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<"\n";
    return 0;
}