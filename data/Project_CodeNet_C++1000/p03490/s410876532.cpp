#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0); cin.sync_with_stdio(false);
  string s; int gx, gy;
  cin >> s >> gx >> gy;
  int n = s.length();
  bool crr = 0; int tmp = 0;
  vector<vector<int>> cmd(2);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'T') {
      if (!i || s[i - 1] == 'F') {
        cmd[crr].push_back(tmp);
        tmp = 0;
      }
      crr ^= 1;
    }
    else tmp++;
  }
  if (tmp) cmd[crr].push_back(tmp);
  vector<unordered_set<int>> psb(2);
  if (cmd[0].empty()) {
    psb[0].insert(0);
  } else {
    psb[0].insert(cmd[0][0]); cmd[0].erase(cmd[0].begin());
  }
  psb[1].insert(0);
  for (int q = 0; q < 2; q++) {
    for (auto const& len : cmd[q]) {
      unordered_set<int> nxs;
      for (auto const& e : psb[q]) {
        nxs.insert(e + len);
        nxs.insert(e - len);
      }
      psb[q] = nxs;
    }
  }
  for (auto e : psb[0]) {
    for (auto f : psb[1]) {
      if (e == gx && f == gy) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}