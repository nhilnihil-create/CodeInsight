#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define f2(i, a, b) for (int i = a; i <= (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rep2(a, n) f(i, a, n)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
long long dp[100010];

int main(void) {
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i, n) { cin >> vec[i]; }
  for (int i = 0; i < 100010; i++) dp[i] = INF;
  dp[0] = 0;
  dp[1] = abs(vec[0] - vec[1]);
  rep2(2, n) {
    dp[i] = min(dp[i - 1] + abs(vec[i] - vec[i - 1]),
                dp[i - 2] + abs(vec[i] - vec[i - 2]));
  }
  cout << dp[n-1] << '\n';
  return 0;
}