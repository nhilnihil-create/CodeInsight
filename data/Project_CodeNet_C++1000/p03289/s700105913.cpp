#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

bool chk(string &s) {
  if (s[0] != 'A') return 0;
  int c = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == 'C' && i >= 2 && i <= s.size() - 2) {
      if (c) return 0;
      else c = 1;
    }
    if (s[i] != 'C' && s[i] < 'a') return 0;
  }
  return c;
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  if (chk(s)) cout << "AC" << '\n';
  else cout << "WA" << '\n';
}
