#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  const int md = (int) 1e9 + 7;
  cin >> n;
  vector<int> a(n);
  range(i, 0, n) cin >> a[i];
  int s = *max_element(a.begin(), a.end());
  vector<int> dp(n + 1);
  vector<int> sum(s + 1);
  dp[n] = 1;
  sum[a[n - 1]]++;
  husk(i, n - 1, -1) {
    dp[i] = sum[a[i]];
    if(i > 0 && a[i - 1] != a[i]) {
      sum[a[i - 1]] += dp[i];
      if(sum[a[i - 1]] >= md) sum[a[i - 1]] -= md;
    }
  }
  cout << dp[0];
  return 0;
}
