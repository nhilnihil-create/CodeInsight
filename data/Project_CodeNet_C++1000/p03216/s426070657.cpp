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
  ll n ;cin>> n ;
  string s ; cin>> s ;
  ll q ; cin>> q ;
  
  rep(ww,q){
  ll k ; cin>> k ;
  ll a=0; ll b=0 ;
  ll ans=0 ;
  ll now=0 ;
  rep(i,n-1){
  if(s[i]=='C') ans+= now ;
  if(s[i]=='D') a++ ;  
  if(s[i]=='M') {b++ ; now+= a ;} 
  
  if(i>=k-1){
  if(s[i-(k-1)]=='D') { a-- ; now-= b ;} 
  if(s[i-(k-1)]=='M') b-- ;
  }
  
  }
  if(s[n-1]=='C') ans+= now ;

  cout<<ans<<endl ;
  }
   return 0 ;
 }

