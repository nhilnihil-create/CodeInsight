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
 ll n,m ; cin>>n>>m ;
 vector<ll> A(n) ;
 rep(i,n) cin>>A[i] ;
 ll now=0 ;
 map<ll,ll> mp ;
 mp[now]++ ;
 rep(i,n){
 now= (now+A[i])%m ;
 mp[now]++ ;
 }
 ll ans=0 ;
 for(auto u : mp){
  ans+= u.se*(u.se-1) ;
 }
 cout<< ans/2 <<endl ;
   return 0 ;
}

