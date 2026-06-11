#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  string S, T; cin >> S >> T;
  vector<vector<int>> dp(S.size() + 1, vector<int> (T.size() + 1, (0)));
  for(int i = 0; i < S.size(); i++) {
    for(int j = 0; j < T.size(); j++) {
      if(S[i] == T[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
      else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
    }
  }
  string ans = "";
  int i = S.size(), j = T.size();
  while(i > 0 && j > 0) {
    if(S[i - 1] == T[j - 1]) {
      ans += S[i - 1];
      i--; j--;
    } else {
      if(dp[i][j - 1] > dp[i - 1][j]) j--;
      else i--;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}