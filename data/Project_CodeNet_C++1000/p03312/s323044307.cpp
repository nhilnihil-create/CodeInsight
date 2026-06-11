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
  vector<ll> sum(n+1) ;
  sum[0]=0 ;
  rep(i,n) sum[i+1]=sum[i]+A[i] ;
  vector<ll> sumd(n+1) ;
  rep(i,n+1) sumd[i]=sum[i]*2 ;
  ll ans=INF ;
  rep2(i,2,n-2){// iは前にある個数
    ll k= sum[i] ;
    ll now = lower_bound(sumd.begin(),sumd.end(),k)-sumd.begin() ;
    ll a=sum[now] ;
    ll b= k-a ;
    ll c= sum[now-1] ;
    ll d= k-c ;
    if(abs(c-d)<abs(a-b)){
      a=c ;
      b= d ;
    }
    /////
    ll kk= sum[n]-k ;
    ll mow= lower_bound(sumd.begin(),sumd.end(),k*2+kk) 
    -sumd.begin() ;
    ll e= sum[mow]-k ;
    ll f= kk- e ;
    ll g= sum[mow-1]-k ;
    ll h= kk- g ;
    if(abs(g-h)<abs(e-f)){
      e=g ;
      f=h ;
    }
    /////
    ll xx = max(max(a,b),max(e,f)) ;
    ll yy=  min(min(a,b),min(e,f)) ;
    chmin(ans,abs(yy-xx)) ;
  }
  cout<<ans<<endl ;
   return 0 ;
 }

