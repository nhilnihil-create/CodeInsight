#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[100010];
const int INF = 110000;
int main(void) {
  dp[0] = 0;
  for (int n = 1; n <= 100000; n++) {
    dp[n] = INF;
    int power = 1;
    while (power <= n) {
      dp[n] = min(dp[n], dp[n - power] + 1);
      power *= 6;
    }
    power = 1;
    while (power <= n) {
      dp[n] = min(dp[n], dp[n - power] + 1);
      power *= 9;
    }
}

  int N;
  cin >> N;
  cout << dp[N] << endl;
  
  return 0;
}