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
bool d[55556] ;
int main(){
 int n ;cin>> n ;
 rep(i,55556) d[i] =0 ;
 vector<int> A(55) ;
 int x= 0 ;
 rep2(i,2,55555){
  if(d[i]) continue ;
  if(i%5==1){
     A[x]=i ;
     x++ ;
  }
  for(int j=1;i*j<=55555;j++){
    if(d[i*j]==0) d[i*j]=1 ;
  }
 }
  rep(i,n) cout<<A[i]<<endl ;
  return 0;
  }