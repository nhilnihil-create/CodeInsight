#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int main() {
  int64_t K,A,B;
  cin>>K>>A>>B;
  if(B-A<=2){cout<<1+K<<endl;}
  else{
    if(K<=A-1){cout<<K+1<<endl;}
    else{int64_t ans=((K-(A-1))/2)*(B-A)+A;
         if((K-(A-1))%2!=0){ans+=1;}
         cout<<ans<<endl;
  }
  }
  return 0;}