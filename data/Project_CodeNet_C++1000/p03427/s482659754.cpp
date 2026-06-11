#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

bool check(string s) {
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != '9') return 0;
  }
  return 1;
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int ans = (s[0] - '0' - 1) + (s.size() - 1) * 9;
  if (check(s)) ans++;
  cout << ans << '\n';
}
