#include<bits/stdc++.h>
using namespace std;
int main(){
  long N;cin>>N;
  vector<long>A(N),B(N),C(N);
  for(long i=0;i<N;i++)cin>>A[i];for(long i=0;i<N;i++)cin>>B[i];
  for(long i=0;i<N;i++)C[i]=A[i]-B[i];
  long c=0;
  for(long i=0;i<N;i++){
    if(C[i]<0){
      c+=(-C[i]+1)/2;
      C[i]=(-C[i])%2;
    }
  }
  for(long i=0;i<N;i++)c-=C[i];
  cout<<(c>=0?"Yes":"No");
}