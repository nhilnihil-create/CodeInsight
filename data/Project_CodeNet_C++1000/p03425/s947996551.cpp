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
  
  int N;
  cin>>N;
  
  vector<string> S(N);
  for(int i=0;i<N;i++){
    cin>>S[i];
  }
  
  vector<long long> app(5);
  for(int i=0;i<N;i++){
    if(S[i][0]=='M'){
      app[0]++;
    }
    else if(S[i][0]=='A'){
      app[1]++;
    }
    else if(S[i][0]=='R'){
      app[2]++;
    }
    else if(S[i][0]=='C'){
      app[3]++;
    }
    else if(S[i][0]=='H'){
      app[4]++;
    }
  }
  
  long long sum=0;
  
  sum+=app[0]*app[1]*app[2];
  sum+=app[0]*app[1]*app[3];
  sum+=app[0]*app[1]*app[4];
  sum+=app[0]*app[2]*app[3];
  sum+=app[0]*app[2]*app[4];
  sum+=app[0]*app[3]*app[4];
  sum+=app[1]*app[2]*app[3];
  sum+=app[1]*app[2]*app[4];
  sum+=app[1]*app[3]*app[4];
  sum+=app[2]*app[3]*app[4];
  
  cout<<sum<<endl;
}
