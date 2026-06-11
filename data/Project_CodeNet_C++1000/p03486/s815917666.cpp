#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int ns = (int)s.size();
  int nt = (int)t.size();
  vector<char> sc(ns), tc(nt);
  for (int i = 0; i < ns; i++) {
    sc[i] = s[i];
  }
  for (int i = 0; i < nt; i++) {
    tc[i] = t[i];
  }
  sort(sc.begin(), sc.end());
  sort(tc.begin(), tc.end(), greater<int>());
  string u, v;
  for (int i = 0; i < ns; i++) {
    u += sc[i];
  }
  for (int i = 0; i < nt; i++) {
    v += tc[i];
  }
  if (u < v) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}