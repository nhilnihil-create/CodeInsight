#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int h, w, d;
  cin >> h >> w >> d;

  map<int, pair<int, int>> a;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int x;
      cin >> x;
      a.insert({x, {i, j}});
    }
  }

  vector<ll> memo(h * w + 1);
  for (int i = 1; i < memo.size(); ++i) {
    if (memo[i] == 0) {
      for (int j = i + d; j < memo.size(); j += d) {
        int x = abs(a[j].first - a[j - d].first);
        int y = abs(a[j].second - a[j - d].second);
        memo[j] = memo[j - d] + x + y;
      }
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    ll ans = memo[r] - memo[l];
    cout << ans << endl;
  }
}