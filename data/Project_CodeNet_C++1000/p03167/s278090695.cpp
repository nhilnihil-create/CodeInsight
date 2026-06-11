#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define lld double
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define all(v) v.begin(),v.end()
#define vc vector
#define rep1(it,v) for(it=v.begin();it!=v.end();it++)
#define ayush ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define input(v) for(auto &it:v)cin>>it
#define inf 1000000007
#define pb push_back

char v1[1005][1005]; ll dp[1005][1005];

ll fun(ll h,ll w)
{
    ll h1=-1; ll w1=-1;
    rep(i,0,h-1) if(v1[i][0]=='#') { h1=i; break; }
    if(h1==-1) h1=h;
    rep(i,0,w-1) if(v1[0][i]=='#') { w1=i; break; }
    if(w1==-1) w1=w;
    rep(i,0,h1-1) dp[i][0]=1; rep(i,h1,h-1) dp[i][0]=0;
    rep(i,0,w1-1) dp[0][i]=1; rep(i,w1,w-1) dp[0][i]=0;
    
    rep(i,1,h-1)
    {
        rep(j,1,w-1)
        {
            if(v1[i][j]=='#') dp[i][j]=0;
            else dp[i][j]=(dp[i-1][j]%inf+dp[i][j-1]%inf)%inf;
        }
    }
    
    return dp[h-1][w-1];
}

int main()
{
    ll h,w; cin>>h>>w;
    rep(i,0,h-1) 
    { rep(j,0,w-1) cin>>v1[i][j]; }
    ll ans=fun(h,w); cout<<ans%inf;
}
