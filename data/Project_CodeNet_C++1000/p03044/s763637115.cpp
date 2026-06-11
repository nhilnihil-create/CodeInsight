#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,ll>;
using Graph= vector<vector<P>>; 
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
 
 vector<bool> seen ;
  ll dist[100005] ;
 void dfs(const Graph&G,int v){
  seen[v]=true ;
  for(auto u :G[v]){
    if(seen[u.first]) continue ;
     dist[u.first] = (dist[v]+u.second)%2ll ;
    dfs(G,u.first) ;
 }
 }
int main(){
   int n ;cin>>n ;
  Graph G(n) ;
  rep(i,n-1){
    int a,b ;ll c ;
    cin>>a>>b>>c ;
    a--; b--;
    G[a].eb(mpa(b,c)) ;
    G[b].eb(mpa(a,c)) ;
  }
  dist[0]=0 ;
  seen.assign(n,false) ;
  dfs(G,0) ;
  rep(i,n){
  cout<<dist[i]<<endl ;
  }
  return 0;
  }