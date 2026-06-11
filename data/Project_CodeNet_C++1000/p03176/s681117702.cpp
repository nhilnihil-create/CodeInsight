#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

using ll = long long;
void update(vector<ll> &bit, int x, ll t) {
  for (; x < (int)bit.size(); x = (x|(x+1))) {
    bit[x] = max(bit[x], t);
  }
}

ll query(const vector<ll> &bit, int x) {
  ll res = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1) {
    res = max(res, bit[x]);
  }
  return res;
}

int main() {

  int n;
  cin >> n;
  vector<int> h(n), a(n);
  int max_h = 0;
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    max_h = max(h[i], max_h);
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<ll> bit(max_h, 0);
  ll ans = a[0];
  update(bit, h[0], ans);
  for (int i = 1; i < n; ++i) {
    ll prev_max = query(bit, h[i]-1);
    ans = max(ans, a[i] + prev_max);
    update(bit, h[i], a[i] + prev_max);
  }
  cout << ans << '\n';

  return 0;
}
