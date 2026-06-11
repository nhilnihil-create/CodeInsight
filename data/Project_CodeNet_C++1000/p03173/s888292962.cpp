#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N),B(N+1);
  for(int i=0;i<N;i++){
    cin>>A[i];
    B[i+1]=B[i]+A[i];
  }
  vector<vector<int>> C(N,vector<int>(N,100000000000000000));
  for(int i=0;i<N;i++)
    C[i][i]=0;
  for(int i=1;i<N;i++){
    for(int j=0;j<N-i;j++){
      for(int k=0;k<i;k++)C[j][j+i]=min(C[j][j+i],C[j][j+k]+C[j+k+1][j+i]);
      C[j][j+i]+=B[j+i+1]-B[j];
    }
  }
  cout<<C[0][N-1]<<endl;
}