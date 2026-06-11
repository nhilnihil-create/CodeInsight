#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int A[5];
  int mod=10;
  rep(i,5){
     cin>>A[i];
     if(A[i]%10==0){
         continue;
     }
     else{
         mod=min(mod,A[i]%10);
     }
  }
  int sum=0;
  rep(i,5){
      if(A[i]%10==0){
          sum+=A[i];
      }
      else{
          sum+=A[i]+10-A[i]%10;
      }
      
  }
  sum-=10-mod;
  
  cout<<sum<<endl;
}