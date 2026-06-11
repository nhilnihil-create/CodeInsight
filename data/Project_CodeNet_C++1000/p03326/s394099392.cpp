#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> x(n, vector<ll>(3));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> x[i][j];
    }
  }
  ll ans = 0;
  for (int i = 0; i < 8; ++i) {
    bitset<3> bs(i);
    vector<ll> v(n);
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (bs[k])
          v[j] += x[j][k];
        else
          v[j] -= x[j][k];
      }
    }
    sort(v.begin(), v.end(), greater<>());
    ll tmp = accumulate(v.begin(), v.begin() + m, 0LL);
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
