#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int l;
  cin >> l;
  int c = 1;
  int r = 0;
  for (; c <= l; r++) {
    c <<= 1;
  }
  r--;
  cout << r + 1 << " ";
  vector<vector<int>> ans;
  int cur = 0;
  c = 1;
  for (int i = 1; i <= r; i++) {
    ans.push_back({i, i + 1, 0});
    ans.push_back({i, i + 1, c});
    cur += c;
    c <<= 1;
  }
  for (int i = r; i >= 1; i--) {
    int gain = (1 << (i - 1));
    if (gain + cur <= l - 1) {
      ans.push_back({i, r + 1, cur + 1});
      cur += gain;
    }
  }
  cout << ans.size() << '\n';
  for (auto v : ans) {
    cout << v[0] << " " << v[1] << " " << v[2] << '\n';
  }
  return 0;
}