/*
    Author: aksayushx
*/
#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define all(a) a.begin(),a.end()
#define mp make_pair
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef long double ld;
ll n;
vector<ll> a,pref;
vector<vector<ll>> dp;

void aksayushx()
{
    cin>>n;
    a.resize(n);
    pref.assign(n+1,0);
    dp.assign(n,vector<ll>(n,pow(10,18)));
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        pref[i+1]=pref[i]+a[i];
        //cout<<pref[i+1]<<' ';
    }
    for(ll l=n-1;l>=0;l--)
    {
        for(ll r=l;r<=n-1;r++)
        {
            if(l==r)
            dp[l][r]=0;
            for(ll i=l;i<r;i++)
            dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]+pref[r+1]-pref[l]);
        }
    }
    cout<<dp[0][n-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test=1;
    //cin>>test;
    while(test--)
        aksayushx();
    return 0;
}
