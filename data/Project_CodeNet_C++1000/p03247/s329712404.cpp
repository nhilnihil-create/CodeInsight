#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> X(n), Y(n);
  int st = 0;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    X[i] = x - y;
    Y[i] = x + y;
    st |= 1 << (abs(x + y) % 2);
  }
  if (st == 3) {
    cout << "-1\n";
    return 0;
  }
  vector<ll> d;
  if (st == 1) d.push_back(1);
  for (int i = 0; i < 38; i++) {
    d.push_back(1LL << 38 - i);
  }
  d.push_back(1);
  cout << d.size() << '\n';
  for (ll x : d) cout << x << ' ';
  cout << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d.size(); j++) {
      int dx = 0;
      int dy = 0;
      if (X[i] > 0) {
        dx = 1;
        X[i] -= d[j];
      } else {
        dx = -1;
        X[i] += d[j];
      }
      if (Y[i] > 0) {
        dy = 1;
        Y[i] -= d[j];
      } else {
        dy = -1;
        Y[i] += d[j];
      }
      if (dx > 0 && dy > 0) cout << 'R';
      if (dx < 0 && dy > 0) cout << 'U';
      if (dx < 0 && dy < 0) cout << 'L';
      if (dx > 0 && dy < 0) cout << 'D';
    }
    cout << '\n';
  }
}
