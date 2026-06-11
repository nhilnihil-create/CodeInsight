#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define rep(i,n) for (long long i=0; i < (n); ++i)
#define rep2(i,n,m) for(long long i=n;i<=m;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll INF=1e18 ;
inline void chmax(ll& a,ll b){a=max(a,b);}
inline void chmin(ll& a,ll b){a=min(a,b);}

int main(){
 int n,x;
 cin>> n>>x ;
 vector<int> A(n) ;
 rep(i,n) cin>> A[i] ;
 sort(A.begin(),A.end()) ;
 int ans=0 ;
 rep(i,n){
   if(A[i]>x){
     break ;
   }
   
   x-=A[i] ;
  ans++ ;
 }
  if(x>0&&ans==n) 
  cout <<n-1<<endl;
   else
   cout<<ans<<endl; 
    return 0;
}