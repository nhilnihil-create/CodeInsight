#include <bits/stdc++.h>
using namespace std;
int INF = 10000;
int main(){
  long long N;
  cin >> N;
  string S = to_string(N);
  int M = S.size();
  vector<vector<int>> dp(M + 1, vector<int>(2, 0));
  dp[0][1] = -INF;
  for (int i = 0; i < M; i++){
    dp[i + 1][0] = dp[i][0] + (S[i] - '0');
    for (int j = 0; j < S[i] - '0'; j++){
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + j);
    }
    dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + 9);
  }
  cout << max(dp[M][0], dp[M][1]) << endl;
}