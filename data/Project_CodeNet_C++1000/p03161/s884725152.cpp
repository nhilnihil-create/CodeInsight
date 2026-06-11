#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int INF = 1001001001;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(100100);
  rep(i,n) cin >> h[i];
  vector<int> dp(100100,INF);
  dp[0] = 0;
  for(int i = 1; i < n; i++) {
    for(int j = 1; j <= k; j++){
      if(i > j-1) {
        dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
      }
    }
  }
  cout << dp[n-1] << endl;
  return 0;
}