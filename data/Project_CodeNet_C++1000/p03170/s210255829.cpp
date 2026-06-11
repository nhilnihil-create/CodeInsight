#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> as(N);
  rep(i, N) cin >> as[i];
  vector<bool> dp(K, false);
  for (int i = 0; i <= K; i++) {
    rep(j, N) {
      if (as[j] <= i) {
        dp[i] = dp[i] | !dp[i - as[j]];
      }
    }
  }
  if (dp[K]) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  return 0;
}