#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
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
long long num_size(long long X){
  int ans=0;
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
  
  int N,X;
  cin>>N>>X;
  
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec[i];
  }
  
  vector<int> P(N+1);
  P[0]=X;
  for(int i=0;i<N;i++){
    P[i+1]=vec[i];
  }
  sort(P.begin(),P.end());
  
  
  int ans=P[1]-P[0];
  
  for(int i=1;i<N;i++){
    ans=GCD(ans,P[i+1]-P[i]);
  }
  
  cout<<ans<<endl;
}