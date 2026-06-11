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
 
// sum(x) x以下の和
// sum(a,b) a以上b以下の和


 int main(){
  ll n, k ; cin>> n>> k ;
  vector<ll> A(n) ;
  rep(i,n) cin>>A[i] ;
  vector<ll> ke(41) ;
  rep(i,n){
    bitset<41> s(A[i]) ;
    rep(j,41){
      if(s[j]) ke[j]++ ;
    }
  }

  bitset<41> base(k) ;
  ll dp[42] ;
  ll ep[42] ;
  dp[0]=0 ;ep[0]=0 ;
  int ok=0 ;
  rep2(i,1,41){
    ll now= ke[41-i] ;
    if(base[41-i]) ok++ ;
    if(ok==0){
      dp[i]=0 ;
      ep[i]=ep[i-1]*2+now ;
    }

    else{
      if(!base[41-i]){
     dp[i]=dp[i-1]*2+max(now,n-now) ;
     ep[i]=ep[i-1]*2+now ;
    }
    
    else{
      if(ok>=2)dp[i]=max(dp[i-1]*2+max(now,n-now),
       ep[i-1]*2+now) ;
      else dp[i]=ep[i-1]*2+now ;
      ep[i]=ep[i-1]*2+(n-now) ;
      
    }
    ok++ ;
    }
   
  }
  
  cout<< max(dp[41],ep[41])<<endl ;
   return 0 ;
 }

