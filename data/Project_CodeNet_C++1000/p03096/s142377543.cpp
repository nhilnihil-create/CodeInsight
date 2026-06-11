#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1000000007;
const int N = 200020;

int dp[N];
int last[N];

signed main() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  memset(dp, 0, sizeof(dp));
  memset(last, -1, sizeof(last));

  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    if(last[x] == -1) {
      dp[i] = dp[i - 1];
    } else if (last[x] == i - 1){
      dp[i] = dp[i - 1];
    } else {
      int idx = last[x];
      dp[i] = dp[i - 1] + dp[idx];
      dp[i] %= mod;
    }
    last[x] = i;
  }

  cout << dp[n] << '\n';

  return 0;
}