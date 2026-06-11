#include <bits/stdc++.h>
using namespace std;

int main() {
  const int64_t mod = 1000000007;
  int n;
  string s;
  cin >> n >> s;
  vector<vector<int64_t>> dp(n, vector<int64_t>(n));
  dp.at(0).at(0) = 1;
  for (int i = 0; i < n - 1; i++) {
    if (s.at(i) == '<') {
      for (int j = 0; j <= i; j++) {
        (dp.at(i + 1).at(j + 1) += dp.at(i).at(j) + dp.at(i + 1).at(j)) %= mod;
      }
    } else {
      for (int j = i; j >= 0; j--) {
        (dp.at(i + 1).at(j) += dp.at(i).at(j) + dp.at(i + 1).at(j + 1)) %= mod;
      }
    }
  }
  cout << accumulate(dp.at(n - 1).begin(), dp.at(n - 1).end(), 0l) % mod << endl;
}
