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
  
  vector<int> num(3);
  cin>>num[0]>>num[1]>>num[2];
  sort(num.begin(),num.end());
  
  int ans=0;
  
  
  while(abs(num[0]-num[2])>1){
    num[0]+=2;
    ans++;
  }
  while(abs(num[1]-num[2])>1){
    num[1]+=2;
    ans++;
  }
  sort(num.begin(),num.end());
  
  if(num[0]<num[1]&&num[1]<num[2]){
    ans+=3;
  }
  else if(num[0]==num[1]&&num[1]<num[2]){
    ans++;
  }
  else if(num[0]<num[1]&&num[1]==num[2]){
    ans+=2;
  }
  
  
  cout<<ans<<endl;
}