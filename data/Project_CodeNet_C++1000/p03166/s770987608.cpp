#include<bits/stdc++.h>
using namespace std;

#define mx 100005
typedef long long int ll;
vector<ll>v[mx];
ll dis[mx];
bool vis[mx];
ll dp[mx];
void dfs(ll sn)
{
    vis[sn]=true;
    for(auto i:v[sn]){
        if(!vis[i]){
            dfs(i);
        }
        dp[sn]=max(dp[sn],dp[i]+1);
    }
}

int main()
{
    ll n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        v[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            dfs(i);
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    cout<<ans<<endl;
}
