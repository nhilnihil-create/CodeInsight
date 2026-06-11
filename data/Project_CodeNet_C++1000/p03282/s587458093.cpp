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
 string s ;
 cin >> s ;
 ll k ;
 cin>> k ;
 char ans= '1' ;
 ll m=s.size() ;
 ll p=min(k,m) ;
 rep(i,p) {
   if(s[i]!='1'){
     ans=s[i] ;
     break ;
   }

 }
 cout <<ans<<endl ;
     return 0;
}