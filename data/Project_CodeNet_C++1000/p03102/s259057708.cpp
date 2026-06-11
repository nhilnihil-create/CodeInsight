#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int N,M,C;
  cin>>N>>M>>C;
  int B[M];
  vector<vector<int>> A(N,vector<int>(M));
  rep(i,M){
      cin>>B[i];
  }
  rep(i,N){
      rep(j,M){
          cin>>A[i][j];
      }
  }
  int cnt=0;
  rep(i,N){
      int sum=C;
      rep(j,M){
          sum+=A[i][j]*B[j];
      }
      if(sum>0){
          cnt++;
      }
  }
  cout<<cnt<<endl;
  
}