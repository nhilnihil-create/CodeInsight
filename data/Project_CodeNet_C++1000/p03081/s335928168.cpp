#include <bits/stdc++.h>
#define dbg() cerr <<
#define name(x) (#x) << ": " << (x) << ' ' <<

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<pair<char, int>> qrs(q);
  for (auto &p : qrs) {
    char dir; cin >> p.first >> dir;
    p.second = dir == 'L' ? -1 : +1;
  }
  auto GetPos = [&](int pos) {
    for (auto &p : qrs) {
      if (s[pos] == p.first) {
        pos += p.second;
      }
      if (pos < 0 || pos == n) return pos;
    }
    return pos;
  };
  auto Check = [&](bool type, int pos) {
    pos = GetPos(pos);
    return type ? (pos >= 0 && pos < n) : (pos == -1);
  };
  auto BinSearch = [&](bool type) {
    int lo = 0, hi = n - 1, ans = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (Check(type, mid)) {
        ans = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    if (type && ans == -1) {
      cout << 0 << endl;
      exit(0);
    }
    return ans;
  };

  cout << BinSearch(1) - BinSearch(0) << endl;
}
