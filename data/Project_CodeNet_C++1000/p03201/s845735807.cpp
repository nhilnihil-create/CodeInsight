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
  vector<ll> A(n) ; rep(i,n) cin>>A[i] ;
  map<ll,map<ll,ll>> mp ;
  rep(i,n){
    ll k= A[i] ;
    ll cnt = 0;
    while(k%2==0){
      k/=2 ;
      cnt++ ;
    }
    cnt-- ;
    mp[cnt][n-k]++ ; //大小逆に入れる
  }
  ll ans= 0;
  for( auto u : mp){
    ll plus=0 ;
    auto v= u.se ;
    for(auto t: v ){
      if(t.se<=0) continue ;
      ll x= n- (t.fi) ;
      ll base = 1ll ;
      while(base<= x){
        base*= 2 ;
      }
       if(x==1){
         plus = (t.se)/2 ;
       }
       else{
         plus = min(v[n-(base-x)],t.se) ;
       }
       ans+= plus ;
       v[n-(base-x)]-= plus ;
       
    }
  }
  cout<<ans<<endl ;
 return 0 ; 
}

