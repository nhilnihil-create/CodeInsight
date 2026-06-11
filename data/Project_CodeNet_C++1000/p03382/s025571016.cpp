
#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define rep(i,n) for (long long i=0; i < (n); ++i)
#define rep2(i,n,m) for(long long i=n;i<=m;i++)
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}
int main() {
 ll n ;
 cin >> n;
 vector<ll> A(n) ;
 rep(i,n) cin>> A[i] ;
 sort(A.begin(),A.end()) ;
 ll k=A[n-1] ;
 ll ans=A[0] ;
 ll small=INF ;
 rep(i,n-1) {
  if( small> abs(A[i]*2-k))  
  ans=A[i] ; 
  small =abs(A[i]*2-k) ;
 }
 cout <<k<<endl;
 cout<<ans<<endl ;
 return 0;
}
