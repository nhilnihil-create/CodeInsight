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
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

 int main(){
  ll n,z,w;cin>>n>>z>>w ;
  vector<ll> A(n) ;rep(i,n) cin>>A[i] ;
  if(n==1) cout<< abs(A[n-1]-w)<<endl ;
  else cout<<max(abs(A[n-1]-A[n-2]),abs(A[n-1]-w))<<endl ;
   return 0;
  }