#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  deque<int> v;
  for (int i = 0; i < n; i++) {
    if (s[i] != 'x') v.push_back(i);
  }
  int m = v.size();
  bool palin = 1;
  for (int i = 0; i < m / 2; i++) {
    if (s[v[i]] != s[v[m - i - 1]]) {
      palin = 0;
      break;
    }
  }
  if (!palin) {
    cout << -1 << '\n';
    return 0;
  }
  int ans = 0;
  v.push_front(-1); v.push_back(n); m += 2;
  for (int i = 0; i < (m - 1) / 2; i++) {
    int r = m - i - 1;
    int a = v[i + 1] - v[i];
    int b = v[r] - v[r - 1];
    ans += abs(a - b);
  }
  cout << ans << '\n';
}
