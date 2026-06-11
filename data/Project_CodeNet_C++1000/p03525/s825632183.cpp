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
  vector<ll> A(n) ;
  rep(i,n) cin>>A[i] ;
  vector<ll> B(13) ;
  rep(i,n) B[A[i]] ++ ;
  ll ans=0 ; bool ok= 0 ;
  for(int i=0 ;i<(1<<13) ; i++ ){
    if(ok)  break ;
    ll bns=100 ;
    bitset<13> s(i) ;
    vector<ll> time ;
    rep(i,13){
      if(B[i]>=3){
        ans=0 ; 
        ok= 1 ;
        break ;
      }
      if(B[i]==2){
        time.pb(i) ;
        time.pb(24-i) ;
      }
      if(B[i]==1){
        if(s[i]==0) time.pb(i) ;
        else time.pb(24-i) ;
      }
    }
    if(ok) break ;
    time.pb(0) ;
    ll k= time.size() ;
    rep(i,k-1){
      rep2(j,i+1,k-1){
        ll a= abs(time[i]-time[j]) ;
        chmin(bns,min(a,24-a)) ;
      }
    }
    chmax(ans,bns) ;
  }
  cout<<ans<<endl ;
   return 0 ;
 }