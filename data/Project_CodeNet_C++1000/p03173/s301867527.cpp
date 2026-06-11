#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int64_t> p(N);
  vector<int64_t> imos(N+1);
  vector<vector<int64_t>> dp(N,vector<int64_t>(N));
  for(int i=0;i<N;i++){
    cin>>p[i];
    imos[i+1]=p[i];
    imos[i+1]+=imos[i];
  }
  for(int i=1;i<N;i++){
    for(int j=i;j<N;j++){
      int a=j-i,b=j;
      int64_t A=167167167167167;
      for(int k=a;k<b;k++){
        A=min(A,dp[a][k]+dp[k+1][b]);
      }
      dp[a][b]=A+imos[b+1]-imos[a];
    }
  }
  cout<<dp[0][N-1]<<endl;
}