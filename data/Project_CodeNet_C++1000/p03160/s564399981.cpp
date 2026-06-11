#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define F(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define ff first
#define ss second
#define yes cout << "YES\n"
#define no cout << "NO\n"
 
 
ll gcdExtended(ll a, ll b){
    if (b == 0){
        return a;
    }
    else
        return gcdExtended(b,a%b);
}
vector<ll>v,dp;
ll func(ll x,ll n)
{
    if(dp[x]!=-1)
    {
        return dp[x];
    }
    if(x>=n-1)
    {
        return 0;
    }
    if(x==n-2)
    {
        return abs(v[n-1]-v[n-2]);
    }
    dp[x]=min(abs(v[x]-v[x+1])+func(x+1,n),abs(v[x]-v[x+2])+func(x+2,n));
    return dp[x];
}
float pi=3.1415926535;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t=1;
   // cin>>t; 
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        F(i,0,n)
        {
            cin>>a[i];
            v.pb(a[i]);
            dp.pb(-1);
        }
        ll ans=func(0,n);
        cout<<ans<<endl;
    }
    return 0;
}