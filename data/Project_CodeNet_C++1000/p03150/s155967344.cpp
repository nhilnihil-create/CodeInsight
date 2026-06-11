#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void solve() {
  string s;
  cin >> s;
  string t = "keyence";
  if (s == t) {
    cout << "YES" << '\n';
    return;
  }
  for (int i = 0; i < s.size(); i++)
  for (int j = i; j < s.size(); j++) {
    string l = s;
    l.erase(i, j - i + 1);
    if (l == t) {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
