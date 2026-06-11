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
  vector<string> A(n) ;
  rep(i,n) cin>>A[i] ;
  ll ans = 0 ;
  ll a=0 ;
  ll b=0 ;
  ll c=0 ;
  rep(i,n){
    ll k= A[i].size() ;
    rep(j,k-1){
     if(A[i][j]=='A'&&A[i][j+1]=='B') ans++ ;
    }
    if(A[i][0]=='B'&&A[i][k-1]=='A' ) a++ ;
    else if(A[i][0]=='B') b++ ;
    else if(A[i][k-1]=='A') c++ ;
  }
  if(a>0){
  ans+= a-1 ;
  if(b>0){
    ans++ ;
    b-- ;
  }
  if(c>0){
    ans++ ;
    c-- ;
  }
  ans+= min(b,c) ;
  }
  else ans+= min(b,c) ;
  cout<<ans<<endl ;
   return 0 ;
 }

