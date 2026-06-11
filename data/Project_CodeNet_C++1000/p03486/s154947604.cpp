#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());

  bool ok = false, eq = true;
  int N = min(s.size(), t.size());
  rep(i,0,N-1) {
    if (s[i] < t[i]) ok = true;
    if (s[i] != t[i]) eq = false;
  }

  if (eq && s.size() < t.size()) ok = true;

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
