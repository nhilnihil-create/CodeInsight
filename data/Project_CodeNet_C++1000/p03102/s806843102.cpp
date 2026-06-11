#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,M,C;cin>>N>>M>>C;
  
  vector<int> B(M);
  for(int i=0;i<M;i++){
    cin>>B[i];
  }
  
  vector<vector<int>> A(N,vector<int>(M));
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin>>A[i][j];
    }
  }
  
  
  int ans=0;
  
  vector<int> sum(N);
  
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      sum[i]+=A[i][j]*B[j];
    }
    if(sum[i]+C>0){
      ans++;
    }
    else{
      ans=ans;
    }
  }  
  
  cout<<ans<<endl;
}