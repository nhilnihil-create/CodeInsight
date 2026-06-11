#include<iostream>
#include<vector>
using namespace std;

int main() {
  int N,K,i,j;
  cin>>N>>K;
  vector<int> h(N), dp(N,1e9+1);
  for (i=0;i<N;i++) cin>>h[i];
  dp[0]=0;
  for (i=1;i<N;i++) {
    for (j=1;j<=i && j<=K;j++) {
      dp[i] = min(dp[i], dp[i-j] + abs(h[i]-h[i-j]));
    }
  }
  cout<<dp[N-1]<<endl;
  return 0;
}
