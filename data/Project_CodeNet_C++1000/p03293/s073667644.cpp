#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s, t;
  cin >> s >> t;
  bool ok = false;
  rep(i, s.size()) {
    string u = s[s.size() - 1] + s.substr(0, s.size() - 1);
    if (u == t) {
      ok = true;
    }
    s = u;
  }
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}