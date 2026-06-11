#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s, t;
  cin >> s >> t;
  bool ok = false;
  rep(i, s.size()) {
    bool same = true;
    rep(j, s.size()) if (s[(i+j)%s.size()] != t[j]) same = false;
    if (same) ok = true;
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}