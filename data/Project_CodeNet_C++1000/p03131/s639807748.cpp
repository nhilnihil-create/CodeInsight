#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t K,A,B;
  cin>>K>>A>>B;
  
  if(B-A<=2){
    cout<<1+K<<endl;
  }
  else{
    if(K<=A){
      cout<<1+K<<endl;
    }
    else{
      int64_t S=A+((K-A+1)/2)*(B-A)+(K-A+1)%2;
      cout<<max(1+K,S)<<endl;
    }
  }
  
}