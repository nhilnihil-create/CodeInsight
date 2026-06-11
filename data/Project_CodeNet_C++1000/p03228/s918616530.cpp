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
  
  long long A,B,K;
  cin>>A>>B>>K;
  
  
  if(K%2==0){
    for(int i=0;i<K/2;i++){
      if(A%2==1){
        A--;
      }
      B+=A/2;
      A/=2;
      if(B%2==1){
        B--;
      }
      A+=B/2;
      B/=2;
    }
    
    cout<<A<<" "<<B;
  }
  else{
    for(int i=0;i<K/2;i++){
       if(A%2==1){
        A--;
      }
      B+=A/2;
      A/=2;
      if(B%2==1){
        B--;
      }
      A+=B/2;
      B/=2;
    }
     if(A%2==1){
        A--;
      }
      B+=A/2;
      A/=2;
    
    cout<<A<<" "<<B;
  }
}