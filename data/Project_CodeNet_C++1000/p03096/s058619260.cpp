#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> c(n);
  for (int i = 0; i < n; i++) cin >> c.at(i);
  
  vector<ll> dp(n), now(2e5 + 1);
  dp.at(0) = 1;
  now.at(c.at(0)) = 1;
  for (int i = 1; i < n; i++) {
    dp.at(i) = dp.at(i - 1);
    if (c.at(i) != c.at(i - 1)) dp.at(i) += now.at(c.at(i));
    dp.at(i) %= MOD;
    now.at(c.at(i)) = dp.at(i);
  }
  
  cout << dp.at(n - 1) << '\n';
}