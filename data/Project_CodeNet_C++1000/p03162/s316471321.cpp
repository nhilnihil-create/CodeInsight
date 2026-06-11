#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define vl vector<long long int>
#define vvl vector<vector<ll> > 
#define fo(i,a,b) for(int i=a;i<b;i++)
#define rof(i,a,b)  for(int i=b;i>=a;i--)
using namespace std;
ll mod=1000000007;

int main()
{
    ll n;cin>>n;
    ll dp[n+1][3];
    ll a[n],b[n],c[n];
    fo(i,0,n)
        cin>>a[i]>>b[i]>>c[i];
    dp[0][0]=a[0],dp[0][1]=b[0],dp[0][2]=c[0];
    fo(i,1,n)
    {
        dp[i][0] = a[i]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = b[i]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = c[i]+max(dp[i-1][1],dp[i-1][0]);
    }
    cout << max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
}

