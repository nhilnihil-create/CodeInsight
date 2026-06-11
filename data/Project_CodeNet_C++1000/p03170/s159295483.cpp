#include <bits/stdc++.h>
using namespace std;


int main() {
  int N,K;
  cin>>N>>K;
  int A[110];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  bool dp[101000]={};
  for(int i=1;i<=K;i++){
    for(int j=0;j<N;j++){
      if(i-A[j]>=0) dp[i]|= !(dp[i-A[j]]);
    }
  }
  if(dp[K]){
    cout<<"First"<<endl;
  }
  else{
    cout<<"Second"<<endl;
  }
  return 0;
}

