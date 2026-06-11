#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  vector<int> w(n), s(n), v(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> s[i] >> v[i];
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) { return s[i] - w[j] < s[j] - w[i]; });

  const int MAXS = 20010;
  vector<long long> dp(MAXS);
  for (int i = 0; i < n; i++) {
    for (int j = s[ord[i]]; j >= 0; j--) {
      dp[j + w[ord[i]]] = max(dp[j + w[ord[i]]], dp[j] + v[ord[i]]);
    }
  }
  
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}