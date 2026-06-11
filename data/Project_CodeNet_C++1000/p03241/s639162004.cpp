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

int main(){
 ll n,m ;cin>>n>>m ;
 ll ans=1 ;
 for( ll i=1; i*i<=m;i++){
   if(m%i==0){
     ll j= m/i ;
     if(j>=n) chmax(ans,i) ;
     if(i>=n) chmax(ans,j) ;
   }
 }
   cout<<ans<<endl ;
  return 0;
  }