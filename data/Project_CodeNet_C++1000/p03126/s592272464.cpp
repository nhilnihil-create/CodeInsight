#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,M;
  cin>>N>>M;
  
  vector<int> K(N);
  
  vector<vector<int>> A(N,vector<int>());
  
  for(int i=0;i<N;i++){
    cin>>K[i];
    A[i].resize(K[i]);
    for(int j=0;j<K[i];j++){
      cin>>A[i][j];
    }
  }
  
  vector<int> check(M,0);
  
  
  for(int i=0;i<N;i++){
    for(int j=0;j<K[i];j++){
      for(int l=1;l<=M;l++){
        if(A[i][j]==l){
          check[l-1]++;
        }
      }
    }
  }
  
  int ans=0;
  
  for(int i=0;i<M;i++){
    if(check[i]==N){
      ans++;
    }
  }
  
  cout<<ans<<endl;
}