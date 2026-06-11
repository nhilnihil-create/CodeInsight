#include<bits/stdc++.h>
using namespace std;

long countXOR(long N){
  long ans;
  if(N%2==0){
    long d=N/2;
    if(d%2==0) ans=N;
    else ans=N+1;
  }
  else{
    long d=(N+1)/2;
    if(d%2==0) ans=0;
    else ans=1;
  }
  return ans;
}
    

int main(){
  long A,B;cin>>A>>B;
  long X,Y;
  if(A==0) X=0;
  else X=countXOR(A-1);
  Y=countXOR(B);
  cout<<(X^Y)<<endl;
}
