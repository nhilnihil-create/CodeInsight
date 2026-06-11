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
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    s += s.front();
    s.erase(0, 1);
    if (s == t) {
      cout << "Yes" << '\n';
      return 0;
    }
  }
  cout << "No" << '\n';
}
