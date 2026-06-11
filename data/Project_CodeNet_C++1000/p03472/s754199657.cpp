#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<int,int>;
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
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

int main(){
  ll n,h ;cin>>n>>h ;
  vector<P> A(2*n) ;
  rep(i,2*n){
    ll x ;
    cin>>x ;
    A[i].fi = x ;
    A[i].se =i ; 
  }
  sort(A.rbegin(),A.rend()) ;
  ll ans=0 ;
  ll sum=h ;
  rep(i,2*n){
   if(sum<=0) break ;
   if(A[i].se%2==1){
    sum-=A[i].fi ;
    ans++ ;
   } 
   else{
   ans +=  (sum+A[i].fi-1)/A[i].fi ;
   break ;
   }
  }
  cout<<ans<<endl ;
  return 0;
  }