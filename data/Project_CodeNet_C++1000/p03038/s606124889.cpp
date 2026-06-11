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
 ll  n, m ;cin>>n>>m ;
 vector<P> A(n+m) ;
 rep(i,n){
     int a ; cin>>a ;
     A[i].fi=a ;
     A[i].se=1ll ;
 }
 rep(i,m){
   ll a,b ;cin>>a>>b ;
   A[i+n].fi=b ;
   A[i+n].se=a ; 
 }
 sort(A.rbegin(),A.rend()) ;
 ll k=n ; ll ans=0 ; ll memo =0 ;
 rep(i,n+m){
   ans+= A[i].fi*A[i].se ;
   k-= A[i].se ;
   if(k<=0){
    memo=A[i].fi ;
    break ;
   }
 }
 ans+= k*memo ;
 cout<<ans<<endl ;
 return 0 ; 
}