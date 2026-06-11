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
 
 
 int main(){
  ll n ; cin>> n ;
  if(n==3){
    cout<<2<<" "<<5<<" "<<63<<endl ;
  }
  else{
    if(n<=15003){
      ll res= n%3 ;
      if(res==0){
        rep(i,n-4) cout<<2*(i+1)<<" " ;
        cout<<3<<" "<<9<<" "<<15<<" "<<21<<endl ;
      }
      else{
        rep(i,n-2) cout<<2*(i+1)<<" " ;
        cout<<3<<" "<<9<<endl ;
      }
      
    }

    else{
      ll w ;
      if(n%2==0) w=15000 ;
      else w=14999 ;
        rep(i,w) cout<<2*(i+1)<<" " ;
        rep(i,n-w){
          if(i==n-w-1) cout<<6*i+3<<endl ;
          else cout<<6*i+3<<" " ;
        }
      

    }
  }
   return 0 ;
 }

