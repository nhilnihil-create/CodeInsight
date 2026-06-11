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

int main(){
  ll n ; cin>>n ;
  vector<ll> A(n) ; rep(i,n) cin>>A[i] ;
 ll j=0 ;
 ll hai=0; ll wa=0 ;
 ll ans=0 ;
 rep(i,n){
    rep(k,n){
    hai = hai^A[j] ;
    wa = wa+ A[j] ;
    if(hai==wa){
    ans++ ;
    if(j==n-1){
      if(i==n-1) break  ;
      ans+= j-i-1 ;
      hai= hai^A[i]^A[j] ;
      wa-=A[i]+A[j] ;
     break ;
    }
    
    j++ ;
    }
    
    
    else{
     ans+= j-i-1 ;
     hai= hai^ A[i]^A[j];
     wa -= A[i]+A[j] ;
        
        break ;
    }
    
    }
 } 
 cout<<ans<<endl ;
 return 0 ; 
}