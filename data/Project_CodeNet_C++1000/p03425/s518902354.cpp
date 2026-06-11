#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void MAIN() {
  int n; cin >> n;
  map<char, int> m;
  set<char> s = {'M', 'A', 'R', 'C', 'H'};
  for (int i = 1; i <= n; i++) {
    string t; cin >> t;
    if (s.count(t[0])) m[t[0]]++;
  }
  int ans = 0;
  vector<char> v(all(s));
  for (int i = 0; i < 3; i++)
  for (int j = i + 1; j < 4; j++)
  for (int k = j + 1; k < 5; k++) {
    ans += m[v[i]] * m[v[j]] * m[v[k]];
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
