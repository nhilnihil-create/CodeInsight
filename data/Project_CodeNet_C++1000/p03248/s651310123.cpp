#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  bool ok = true;
  if(s[0] != '1' || s[n - 1] != '0') ok = false;
  rep(i, n / 2) if(s[i] != s[n - 2 - i]) ok = false;
  if(!ok) {
    cout << -1 << endl;
    return 0;
  }
  rep2(i, n / 2 + 1, n) s[i] = '0';
  reverse(all(s));
  vector<vector<int>> g(n);
  int u = 0, v = 0;
  rep2(i, 1, n) {
    v++;
    g[u].push_back(v);
    if(s[i] == '1') u = v;
  }
  set<P> st;
  rep(i, n) for(auto v : g[i]) st.insert({min(i, v), max(i, v)});
  for(auto p : st) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
}