#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct ftree {
  vector<int> bit;
  void update(int x, int val) {
    while (x < (int)bit.size()) {
      bit[x] = max(bit[x], val);
      x += x&-x;
    }
  }

  int query(int x) {
    int ret=0;
    while (x > 0) {
      ret = max(ret, bit[x]);
      x -= x&-x;
    }
    return ret;
  }
};

int32_t main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin >> n;

  ftree bit;
  bit.bit.resize(n + 5, 0);
  
  vector<pair<pair<int, int>,int>> f(n);
  for (int i = 0; i < n; ++i) {
    cin >> f[i].first.first;
  }
  for (int i = 0; i < n; ++i) {
    cin >> f[i].first.second;
    f[i].second = i + 1;
  }
  
  int ans = 0;
  sort(f.begin(), f.end());
  for (int i = 0; i < n; ++i) {
    int val = bit.query(f[i].second);
    ans = max(ans, val + f[i].first.second);
    bit.update(f[i].second, val + f[i].first.second);
  }
  cout << ans << '\n';
}
