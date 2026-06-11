#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxn=1e5+10;
ll vis[mxn];
vector<ll> adj[mxn];
ll dp[mxn];

vector<ll> top;

void dfs(ll u){
  vis[u]=1;
  for(auto c:adj[u]){
    if(!vis[c]){
      dfs(c);
    }
  }
  top.push_back(u);
}

int main(){
  ll n,m;
  cin >> n >> m;
  ll i,j;
  ll x,y;
  for(i=0;i<m;i++){
    cin >> x >> y;
    adj[x].push_back(y);
  } 

  for(i=1;i<=n;i++){
    if(!vis[i]){
      dfs(i);
    }
  }
  ll mx=0;
  for(auto c:top){
    ll ans=0;
    //cout << c << endl;
    for(auto d:adj[c]){
      ans=max(ans,dp[d]);
    }
    ans++;
    dp[c]=ans;
    mx=max(mx,ans);
  }
  cout << mx-1 << endl;



}