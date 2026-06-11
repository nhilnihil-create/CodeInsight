#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>vec(N),dp(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  dp[0] = 0,dp[1] = abs(vec[1]-vec[0]);
  for(int i=2; i<N; i++){
    dp[i] = min(dp[i-2]+abs(vec[i]-vec[i-2]),dp[i-1]+abs(vec[i]-vec[i-1]));
  }
  cout << dp[N-1] << endl;
}
