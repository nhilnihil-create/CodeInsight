#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<ll> march(5, 0);
  string st;
  for (int i = 0; i < n; ++i) {
    cin >> st;
    if (st[0] == 'M') ++march[0];
    if (st[0] == 'A') ++march[1];
    if (st[0] == 'R') ++march[2];
    if (st[0] == 'C') ++march[3];
    if (st[0] == 'H') ++march[4];
  }

  ll ans = 0;
  for (int i = 0; i < 5; ++i) {
    for (int j = i + 1; j < 5; ++j) {
      for (int k = j + 1; k < 5; ++k) {
        if (march[i] != 0 && march[j] != 0 && march[k] != 0) {
          ans += march[i] * march[j] * march[k];
          // cout << i << " " << j << " "<< k << endl;
        }
      }
    }
  }
  cout << ans << endl;
}
