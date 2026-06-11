#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 100001;

int main() {
  ll n;
  cin >> n;

  vector<int> dp(n + 1, INF);
  dp[0] = 0;
  int power;

  for (int i = 1; i <= n; i++) {
    power = 1;
    while (power <= i) {
      dp[i] = min(dp[i], dp[i - power] + 1);
      power *= 6;
    }

    power = 1;
    while (power <= i) {
      dp[i] = min(dp[i], dp[i - power] + 1);
      power *= 9;
    }
  }
  cout << dp[n] << endl;
  return 0;
}
