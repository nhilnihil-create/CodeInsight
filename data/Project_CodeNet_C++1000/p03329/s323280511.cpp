#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 0;
  rep(i, 1, n + 1) {
    dp[i] = dp[i - 1] + 1;

    for (int j = 6; j <= i; j *= 6)
      chmin(dp[i], dp[i - j] + 1);
    for (int j = 9; j <= i; j *= 9)
      chmin(dp[i], dp[i - j] + 1);
  }

  cout << dp[n] << endl;
}
