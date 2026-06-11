#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<int> dp(100005,INF);
  dp[0] = 0;
  for(int i=0; i<100000; ++i){
    dp[i+1] = min(dp[i+1], dp[i]+1);
    for(int j=6; i+j<=100000; j*=6){
      dp[i+j] = min(dp[i+j], dp[i] +1);
    }
    for(int j=9; i+j<=100000; j*=9){
      dp[i+j] = min(dp[i+j], dp[i] +1);
    }
  }
  cout << dp[n] << endl;
}