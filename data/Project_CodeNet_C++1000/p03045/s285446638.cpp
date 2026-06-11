#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph= vector<vector<ll>>; 
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

vector<bool> seen ;
void dfs(const Graph &g,ll i){
  seen[i]=true ;//訪問済みに初期化
  for(ll u:g[i]){
   if(seen[u]) continue ;
    dfs(g,u) ;//今度はuから出発して同じ操作
  }
}


int main(){
  ll n,m  ;
  cin>> n>>m ;
  Graph g(n) ;
  rep(i,m){
    ll a,b,c ;
    cin>>a>>b>>c ;
    a--;b--;
    g[a].pb(b) ;
    g[b].pb(a) ;
  }
  int ans=0;
  seen.assign(n,false);//すべて未訪問に初期化
    rep(i,n){
      if(seen[i]) continue ;
      dfs(g,i)   ;     //iから出発するdfs
      ans++ ;          //一つのdfsが終わるたびにカウント
    }
    cout<<ans<<endl ;
    return 0;
  }