#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, ss;
  cin >> s;

  rep(i, s.size()) {
    rep(j, s.size() - i) {
      ss = s;
      ss.erase(i, j);
      if (ss == "keyence") {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
