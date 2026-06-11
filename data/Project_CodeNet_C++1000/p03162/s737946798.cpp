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
int dp[100001][3];
int ans(vector<vector<int>>&v,int x,int n){
    if(n==0)
    return 0;
    if(dp[n][x]!=-1)
    return dp[n][x];
    if(x==0){
        return dp[n][x] = max(ans(v,1,n-1)+v[n-1][x],ans(v,2,n-1)+v[n-1][x]);
    }
    else if(x==1){
         return dp[n][x] = max(ans(v,0,n-1)+v[n-1][x],ans(v,2,n-1)+v[n-1][x]);   
    }
    else
     return dp[n][x] = max(ans(v,1,n-1)+v[n-1][x],ans(v,0,n-1)+v[n-1][x]);
}
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
     vector<vector<int>>v;
     for(int i=0;i<n;i++){
         vector<int>temp;
         int x,y,z;
         cin>>x>>y>>z;
         temp.pb(x);
         temp.pb(y);
         temp.pb(z);
         v.pb(temp);
     }
     memset(dp,-1,sizeof(dp));
     cout<<max(ans(v,0,n),max(ans(v,1,n),ans(v,2,n)));
    }
}