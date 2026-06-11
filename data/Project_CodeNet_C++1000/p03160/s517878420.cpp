#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(p,n) for(int i=p;i<n;i++)
#define FIO ios_base::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);
#define endl "\n"
#define mp make_pair
#define pb push_back
#define M 1000000007
ll mod(ll x){
return ((x%M + M)%M);
}
ll add(ll a,ll b){
return mod(mod(a)+mod(b));
}
ll mul(ll a,ll b){
return mod(mod(a)*mod(b));
}

// ....................................................................................

int main()
{
    FIO
    ll t;
    t=1;
    // cin>>t;
    while(t--)
    {
     int n;
     cin>>n;
     int a[n];
     fo(0,n)
     cin>>a[i];
     int dp[n];
     fo(0,n)
     dp[i]=INT_MAX;
     dp[0]=0;
     for(int i=1;i<n;i++){
         dp[i]=min(dp[i],abs(a[i]-a[i-1])+dp[i-1]);
         if(i-2>=0)
         dp[i]=min(dp[i],abs(a[i]-a[i-2])+dp[i-2]);
     }
     cout<<dp[n-1];
    }
}