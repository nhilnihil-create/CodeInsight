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
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int n; cin >> n;
  int c = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') c = i + 1;
    else break;
  }
  if (n <= c) cout << 1 << '\n';
  else cout << s[c] << '\n';
}
