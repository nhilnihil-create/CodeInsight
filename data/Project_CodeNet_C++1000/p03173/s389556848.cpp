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
 ll n ;
 vector<ll> A(n) ;
 bool flag[405][405] ;
 ll   dp[405][405] ;

 ll f(ll a, ll b ){
  if(flag[a][b]) return dp[a][b] ;
  else{
     if(a==b){
       flag[a][b]=0 ;
       dp[a][b]= 0 ;
       return 0 ;
     }
     else if(a==b-1){
      flag[a][b]=1 ;
      dp[a][b]=A[a]+A[b] ;
      return A[a]+A[b] ;
    }
  else{
    ll ans= INF ;
    rep2(i,a,b-1){
     chmin(ans, f(a,i)+f(i+1,b)) ;
    }
    rep2(i,a,b) ans+= A[i] ;
    flag[a][b]=1 ;
  dp[a][b]=ans ;
    return ans ;
  }
  
  }
}

 int main(){
   cin>> n ;
  A.assign(n,0) ;
  rep(i,n){
   cin>>A[i] ;
  }
   rep(i,405){
    rep(j,405){
      flag[i][j]=0 ;
      dp[i][j]=0 ;
    }
  }
  
   cout<< f(0,n-1)<<endl ; 

   return 0 ;
 }

