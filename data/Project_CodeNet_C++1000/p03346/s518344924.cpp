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
 cin >> n ;
 vector<int> A(n) ;
 rep(i,n) cin >>A[i] ;
 vector<int> B(n) ;
 rep(i,n) B[A[i]-1] =i;
 ll ans=0 ;
 ll len=1 ;
 rep(i,n-1){
   if(B[i]<B[i+1]) {
    len ++ ;
  }
  else len=1 ;
   ans= max(ans,len) ;
 }
  if(n==1)
  cout <<0 <<endl ;
   else
   cout << n-ans <<endl ;
     return 0;
}
