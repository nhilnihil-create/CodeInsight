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
 int n; 
 cin >> n;
 string s ;
 cin >> s ;
 ll kaisuu = 0;
 rep2(i,1,n-1) if(s[i]=='E') kaisuu ++ ;
 ll ans= kaisuu ;
 rep(i,n-1){
   if(s[i]=='E'&&s[i+1]=='E')
   kaisuu--;
   if(s[i]=='W'&& s[i+1]=='W')
   kaisuu ++ ;
   ans=min(ans,kaisuu) ;
 } 
 cout <<ans<<endl ;
     return 0;
}
