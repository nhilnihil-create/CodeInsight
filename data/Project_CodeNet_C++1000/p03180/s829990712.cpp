#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<vector<ll>> a(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a.at(i).at(j);
    }
  }
  
  vector<ll> cost(1 << n, 0);
  for (int bit = 1; bit < (1 << n); bit++) {
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if ((bit & (1 << i)) && (bit & (1 << j))) cost.at(bit) += a.at(i).at(j);
      }
    }
  }
  
  vector<ll> dp(1 << n);
  dp.at(0) = 0;
  
  for (int bit = 1; bit < (1 << n); bit++) {
    dp.at(bit) = cost.at(bit);
    for (int s = bit; s > 0; s = (s - 1) & bit) {
      if (bit == s) continue;
      dp.at(bit) = max(dp.at(bit), dp.at(bit - s) + cost.at(s));
    }
  }
  
  cout << dp.at((1 << n) - 1) << '\n';
}