#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)

int main() {
  string s;
  cin >> s;
  int n = s.size(), u = 1, v = 1;
  bool ok = true;
  if(s[0] != '1' || s[n - 1] != '0') ok = false;
  rep(i, n / 2) if(s[i] != s[n - 2 - i]) ok = false;
  if(!ok) {
    cout << -1 << endl;
    return 0;
  }
  rep(i, n / 2 + 1) s[n / 2 + 1 + i] = '0';
  reverse(all(s));
  vector<pair<int, int>> g;
  rep(i, n - 1) {
    v++;
    g.push_back({u, v});
    if(s[i + 1] == '1') u = v;
  }
  for(auto p : g) cout << p.first << ' ' << p.second << '\n';
}