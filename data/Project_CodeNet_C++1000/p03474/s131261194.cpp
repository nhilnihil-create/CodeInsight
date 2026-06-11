#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b;
  cin >> a >> b;
  string s; cin >> s;
  if (s[a] != '-') {
    cout << "No" << '\n';
    return 0;
  }
  s.erase(a, 1);
  for (auto &i : s) {
    if (i < '0' || i > '9') {
      cout << "No" << '\n';
      return 0;
    }
  }
  cout << "Yes" << '\n';
}
