#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Graph= vector<vector<ll>>;
struct edge{ll to ; ll cost ;} ;
using graph =vector<vector<edge>> ;
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
#define fi first
#define se second 
#define set20 cout<<fixed<<setprecision(20) ;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
double pi=acos(-1) ;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
 
 ll n; 
 vector<bool> seen ;
 vector<ll> ans ;
 ll cnt ;
void dfs( const Graph & g ,ll st ){
  seen[st]=1 ; ans[st]= cnt ; 
  cnt++ ;
  for( auto next : g[st]){
    if(seen[next]) continue ;
      
      dfs(g,next) ;
  }

}

 int main(){
  cin>>n ;
  Graph G(n) ;
  rep(i,n-1){
    ll a, b ; cin>>a>>b ;
    a-- ; b--; 
    G[a].pb(b) ;
    G[b].pb(a) ;
  }
  vector<ll> X(n) ;
  rep(i,n) cin>>X[i] ;
  sort(X.rbegin(),X.rend()) ;
  ll bns=0 ;
  rep(i,n-1)  bns+= X[i+1] ;
  seen.assign(n,false) ;
  ans.assign(n,0) ;
  cnt= 0 ;
  dfs(G,0) ;
  cout<<bns<<endl ;
  rep(i,n){
    if(i==n-1) cout<< X[ans[i]]<<endl ;
    else cout<<X[ans[i]]<<" " ;
  }
  
  return 0 ;
}


