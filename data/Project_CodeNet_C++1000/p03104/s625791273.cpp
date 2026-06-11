#include <bits/stdc++.h>
using namespace std;

long long fxor(long long n){
  long long ans=0;
  if((n/2)%2==0 && n%2==0){
    ans=n;
  }
  else if((n/2)%2==0 && n%2==1){
    ans=n^(n-1);
  }
  else if((n/2)%2==1 && n%2==0){
    ans=n^1;
  }
  else{
    ans=0;
  }
  return ans;
}
    

int main(){
  long long A,B;
  cin>>A>>B;
  long long res;
  res=(fxor(A-1))^(fxor(B));
  //cout<<fxor(A-1)<<" "<<fxor(B)<<endl;
  cout<<res<<endl;
  
  return 0;
}

