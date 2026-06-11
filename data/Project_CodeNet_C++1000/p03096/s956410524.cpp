#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 2e5 + 10;

int main() {
  int N;
  cin >> N;
  vector<int> a(N + 1);
  for_each(begin(a), prev(end(a)), [](auto &e) {
    cin >> e;
  });

  vector<int> tmp(MAX);
  vector<int> dp(MAX);
  dp[0] = 1;
  tmp[a[0]] = 1;
  for (int i = 0; i < N; i++) {
    if (a[i] == a[i + 1]) {
      continue;
    }

    dp[i + 1] = tmp[a[i]];
    (tmp[a[i + 1]] += dp[i + 1]) %= MOD;
  }
  cout << dp[N] << endl;
}
