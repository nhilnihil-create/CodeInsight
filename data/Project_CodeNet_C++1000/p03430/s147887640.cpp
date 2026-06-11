#include<bits/stdc++.h>
using namespace std;
int main() {
  string S;
  int K;
  cin >> S >> K;
  vector<vector<int>> dp(S.size()+1, vector<int>(S.size()+1));
  for(auto i = 0; i < S.size(); ++i) dp[i][i+1] = 1;
  for(auto k = 0; k <= K; ++k) {
    auto dup = dp;
    for(auto w = 2; w <= S.size(); ++w) for(auto l = 0; l+w <= S.size(); ++l) {
      auto r = l + w;
      dp[l][r] = max({dp[l][r], dp[l+1][r], dp[l][r-1]});
      if(k)            dp[l][r] = max(dp[l][r], 2 + dup[l+1][r-1]);
      if(S[l]==S[r-1]) dp[l][r] = max(dp[l][r], 2 + dp[l+1][r-1]);
    }
  }
  cout << dp[0][S.size()] << endl;
}
