#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  vector<int> dp(n,INF);
  dp[0] = 0;
  for(int i = 1; i < n; i++) {
    dp[i] = min(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
    if(i > 1) dp[i] = min(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
  }
  cout << dp[n-1] << endl;
  return 0;
}