#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph= vector<vector<int>>; 
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define mpa make_pair
#define fi first
#define se second
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};
 int main(){
   ll n , m ; cin>> n>>m ;
   vector<P> A(m) ;
   rep(i,m){
     ll a , b; cin>>a>>b ;
     a-- ; b-- ;
     A[i].fi= a ;A[i].se= b ;
   }
   ll ans=0 ;
   rep(i,m){
    UnionFind uf(n) ;
    rep(j,m){
    if(j==i) continue ;
     uf.unite(A[j].fi,A[j].se) ;
    }
   bool ok= 1 ;
   rep(i,n-1){
     rep2(j,i+1,n-1){
       if(!uf.same(i,j)) ok= 0;
     }
   }

  if(!ok) ans++ ;
   }
   
   cout<<ans<<endl ;
   return 0;
  }