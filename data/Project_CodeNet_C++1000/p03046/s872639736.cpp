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
 ll m,k ; cin>>m>>k ;
 if(m==0){
   if(k==0) cout<<0<<" "<<0<<endl ;
   else cout<< -1<<endl ;
 }
 else if(m==1){
   if(k==0) cout<<0<<" "<<0<<" "<<1<<" "<<1<<endl ;
   else cout<<-1<<endl ;
 }
 else{
   if(k>pow(2,m)-1) cout<<-1<<endl ;
   else{
    ll d= pow(2,m)-1 ;
    rep(i,d+1){
      if(i<k) cout<< i<<" " ;
      if(i>=k&&i!=d) cout <<i+1<<" " ;
      if(i==d) cout<<k<<" " ;
    }
    rep3(i,d,0){
     if(i>k) cout<<i<<" " ;
     if(i<=k&&i!=0) cout<< i-1<<" " ;
     if(i==0) cout<<k<<endl ; 
    }
   }
 }
   return 0 ;
 }

