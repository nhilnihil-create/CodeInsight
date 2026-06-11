#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<char> fmr(n);
  vector<char> ltr(n);
  for (int i = 0; i < n; i++) {
    cin >> fmr[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> ltr[n - 1 - i];
  }
  long long ret = 0;
  const int BSM = (1 << n);
  for (int bs = 0; bs < BSM; bs++) {
    vector<char> a;
    vector<char> b;
    int k(0), l(0);
    for (int i = 0; i < n; i++) {
      if (bs & (1 << i)) {
        a.push_back(fmr[i]);
        k++;
      } else {
        b.push_back(fmr[i]);
        l++;
      }
    }
    vector<vector<int>> dp(k + 1, vector<int>(l + 1, 0));
    dp[0][0] = 1;
    for (int d = 1; d <= n; d++) {
      for (int i = max(0, d - l); i <= min(k, d); i++) {
        int j = d - i;
        if (i && ltr[d - 1] == a[i - 1]) {
          dp[i][j] += dp[i - 1][j];
        }
        if (j && ltr[d - 1] == b[j - 1]) {
          dp[i][j] += dp[i][j - 1];
        }
      }
    }
    ret += dp[k][l];
  }
  cout << ret << '\n';
  return 0;
}