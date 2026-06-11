#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
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
#define set20 cout<<fixed<<setprecision(20) ;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
double pi=acos(-1) ;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

ll d[100005] ; ll f[100005];
ll e[100005] ;
ll sum[100005] ;
int main(){
  rep(i,100005){
      d[i]=0 ;
      e[i]=0 ;
      f[i]=0 ;
  } 
  rep2(i,2,100003){
      if(d[i]!=0) continue ;
      f[i]=87 ;
      for(ll j=1 ; i*j<=100000;j++){
          d[i*j]++ ;
      }
  }
  rep(i,49999){
      ll a= 2*i+1 ;
      if(f[i+1]==87&&f[a]==87) e[a]++ ;

  }
  sum[0]=e[0] ;
  rep(i,100002){
      sum[i+1]= sum[i]+e[i+1] ;
  }
  ll q ;cin>> q ;
  while(q--){
    ll x,y ;
    cin>>x>>y ;
    cout<< sum[y]-sum[x-1] <<endl ;
  }
 return 0 ; 
}