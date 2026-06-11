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
 int  n ;
 cin >> n ;
vector<int> A(n) ;
vector<int> B(n) ;
vector<int> C(n) ;
rep(i,n) cin>> A[i] ;
rep(i,n) cin >> B[i] ;
rep(i,n) cin >>C[i] ;
sort(A.begin(),A.end()) ;
sort(C.begin(),C.end()) ;
ll ans=0 ;
rep(i,n){
ll p= lower_bound(A.begin(),A.end(),B[i])-A.begin() ;
ll q= upper_bound(C.begin(),C.end(),B[i])-C.begin() ;
ans+= p*(n-q) ;
}
 
 cout <<ans<<endl ;
     return 0;
}