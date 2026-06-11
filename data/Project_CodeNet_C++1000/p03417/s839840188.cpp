#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define PI 3.1415926535897932
#define MOD 1000000007;
using namespace std;
long long GCD(long long A,long long B){
  if(B==0){
    return A;
  }
  else{
    return GCD(B,A%B);
  }
}
long long LCM(long long A,long long B){
  long long g=GCD(A,B);
  return A/g*B;
}
long long num_order(long long X){
  long long ans=0;
  while(true){
    if(X==0){
      break;
    }
    else{
      X/=10;
      ans++;
    }
  }
  return ans;
}
int main() {
  
  long long N,M;
  cin>>N>>M;
  
  long long ans=0;
  
  
  if(N==1&&M==1){
    ans=1;
  }
  else if(N==1||M==1){
    ans=N*M-2;
  }
  else{
    ans=(N-2)*(M-2);
  }
  
  cout<<ans<<endl;
}