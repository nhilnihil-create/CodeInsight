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
 int n;
 cin>> n;
 vector<int> A(n) ;
 rep(i,n) cin>> A[i] ;
 int ans=0 ;
 int k= 0;
 rep(i,n-1){
   
   if(A[i]!=A[i+1]){
     ans+= (k+1)/2 ;
     k=0 ;
   }
  else if(i==n-2){
    ans+= (k+2)/2 ;
   }
   else
   k++ ;
 }
   cout<<ans<<endl; 
    return 0;
}