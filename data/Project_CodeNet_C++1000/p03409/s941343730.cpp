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
 ll n ; cin>>n ;
 vector<P> A(n),B(n) ;
 rep(i,n) cin>>A[i].fi>>A[i].se ;
 rep(i,n) cin>>B[i].fi>>B[i].se ;
 vector<ll> flag(n) ;
 sort(A.begin(),A.end()) ;
 sort(B.begin(),B.end()) ;
 ll ans=0 ;
 rep(i,n){
   ll x= B[i].fi ;
   ll y= B[i].se ;
   ll now= -1 ;
   ll memo =-1 ;
   rep(j,n){
    if(A[j].fi<x&&A[j].se<y&&now<A[j].se&&flag[j]==0){
      memo=j ;
      now= A[j].se ;
    }
   }
   if(now!=-1){
     ans++ ;
     flag[memo]=1 ;
   }

 }
  cout<<ans<<endl;
   return 0 ;
}

