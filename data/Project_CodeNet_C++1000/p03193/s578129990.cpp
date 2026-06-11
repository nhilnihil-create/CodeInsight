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
  
  long long N,H,W;
  cin>>N>>H>>W;
  
  vector<vector<long long>> vec(N,vector<long long>(2));
  for(int i=0;i<N;i++){
    cin>>vec[i][0]>>vec[i][1];
  }
  
  long long sum=0;
  
  
  for(int i=0;i<N;i++){
    if(vec[i][0]>=H&&vec[i][1]>=W){
      sum++;
    }
  }
  
  
  cout<<sum<<endl;
}