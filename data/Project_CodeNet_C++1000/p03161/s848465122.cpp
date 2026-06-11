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
int dp[100001];
int fun(int a[],int i,int k){
    if(i==0)
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    dp[i]=INT_MAX;
    for(int j=1;j<=k;j++){
        if(i-j>=0)
        dp[i]=min(dp[i],abs(a[i]-a[i-j])+fun(a,i-j,k));
        else break;
    }
    return dp[i];
}
int main()
{
    FIO
    ll t;
    t=1;
    // cin>>t;
    while(t--)
    {
     int n,k;
     cin>>n>>k;
     int a[n];
     fo(0,n)
     cin>>a[i];
     memset(dp,-1,sizeof(dp));
     dp[0]=0;
     cout<<fun(a,n-1,k)<<endl;
    }
}