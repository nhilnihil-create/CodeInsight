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
 int h,w ;
 cin >>h>> w;
 char A[h][w] ;
 rep(i,h){
   rep(j,w) cin>>A[i][j] ;
 }
 int ans=0 ;
 rep2(i,1,h-1){
   rep2(j,1,w-1){
     int p=1 ;
     if(A[i][j]=='#'){
      if(((A[i-1][j]=='.')&&(A[i+1][j]=='.'))&&
      ((A[i][j-1]=='.')&&(A[i][j+1]=='.'))) p=2 ;
     }
   if(p==2) ans=1 ;
   }
 }
 if(ans==0)
 cout <<"Yes"<< endl ;
 else 
 
 cout <<"No"<<endl ;
     return 0;
}