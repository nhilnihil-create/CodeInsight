#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> dp(n+1,INF);
  dp[0] = 0;
  for(int i = 1; i <= n; i++) {
    dp[i] = dp[i-1]+1;
    for(int j = 1; pow(6,j) <= n; j++) {
      int six = pow(6,j);
      if(i < six) break;
      dp[i] = min(dp[i], dp[i-six]+1);
    }
    for(int j = 1; pow(9,j) <= n; j++) {
      int nine = pow(9,j);
      if(i < nine) break;
      dp[i] = min(dp[i], dp[i-nine]+1);
    }
  }
  cout << dp[n] << endl;
  return 0;
}