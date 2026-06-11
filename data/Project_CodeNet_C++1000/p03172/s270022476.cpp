#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
signed main(){
  int N,K;
  cin>>N>>K;
  vector<int> A(N);
  for(int &i:A)
    cin>>i;
  vector<vector<int>> B(N+1,vector<int>(K+1,0));
  B[0][0]=1;
  for(int i=0;i<N;i++){
    for(int j=0;j<=K;j++){
      B[i+1][j]=(B[i+1][j]+B[i][j])%mod;
      if(j+A[i]+1<=K)
        B[i+1][j+A[i]+1]=(B[i+1][j+A[i]+1]-B[i][j]+mod)%mod;
    }
    for(int j=1;j<=K;j++)
      B[i+1][j]=(B[i+1][j]+B[i+1][j-1])%mod;
  }
  cout<<B[N][K]<<endl;
}