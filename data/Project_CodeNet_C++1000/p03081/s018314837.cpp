#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, q;
  string s;
  cin >> n >> q >> s;
  
  vector<char> t(q), d(q);
  for (int i = 0; i < q; i++) cin >> t.at(i) >> d.at(i);
  
  int dead_l = -1, alive_l = n;
  while (alive_l - dead_l > 1) {
    int mid = (dead_l + alive_l) / 2;
    int it = mid;
    for (int i = 0; i < q; i++) {
      if (s.at(it) == t.at(i)) {
        if (d.at(i) == 'L') it--;
        else it++;
      }
      if (it < 0 || it >= n) break;
    }
    if (it < 0) dead_l = mid;
    else alive_l = mid;
  }
  
  int alive_r = -1, dead_r = n;
  while (dead_r - alive_r > 1) {
    int mid = (dead_r + alive_r) / 2;
    int it = mid;
    for (int i = 0; i < q; i++) {
      if (s.at(it) == t.at(i)) {
        if (d.at(i) == 'L') it--;
        else it++;
      }
      if (it < 0 || it >= n) break;
    }
    if (it >= n) dead_r = mid;
    else alive_r = mid;
  }
  
  cout << alive_r - alive_l + 1 << '\n';
}