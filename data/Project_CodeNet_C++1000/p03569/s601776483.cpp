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
  string s ; cin>> s ;
  ll k= s.size() ;
  string t ="" ;
  rep(i,k){
   if(s[i]!='x') t+= s[i] ;
  }
  ll z = t.size() ;
  bool ok=1 ;
  rep(i,z/2){
    if(t[i]!=t[z-1-i]) ok= 0 ;
  }
  if(!ok) cout<<-1<<endl ;
  else{
    ll x= z+1 ;
    vector<ll> A(x) ;
    ll j= 0 ;
    rep(i,k){
     if(s[i]=='x') A[j] ++ ;
     else j++ ;
    }
    ll ans=0 ;
    rep(i,x/2){
     ans+= max(A[i],A[x-1-i]) - min(A[i],A[x-1-i]) ;
    }
    cout<<ans<<endl ;
  }
   return 0 ;
 }