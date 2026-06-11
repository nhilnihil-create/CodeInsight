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
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
int main() {
   int n ;cin>>n ;
   vector<ll>A(n) ;
   rep(i,n) cin>>A[i] ;
 bool ok=1 ;
 if(A[0]!=0) ok=0 ;
 ll ans=0 ;
 rep(i,n-1){
   if(A[i+1]-A[i]>=2) ok=0 ;
   if(A[i+1]<=A[i]) ans+=A[i] ;
 }
 if(ok==0) cout<<-1<<endl ;
 else
 cout<<ans+A[n-1]<<endl ;
  return 0;
}