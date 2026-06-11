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
  int n;
  cin >> n;
  string o;
  set<string> d;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if ((i > 1 && o.back() != s.front()) || d.count(s)) {
      cout << "No" << '\n';
      return 0;
    }
    o = s;
    d.insert(s);
  }
  cout << "Yes" << '\n';
}
