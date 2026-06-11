#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  bool is_key = false;
  for (int l = 0; l <= n; ++l) {
    for (int r = l; r <= n; ++r) {
      string t = "";
      rep(i, l) t += s[i];
      for (int i = r; i < n; ++i) t += s[i];
      if (t == "keyence") is_key = true;
    }
  }
  if (is_key) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}