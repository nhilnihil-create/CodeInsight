#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d[i];
  int m;
  cin >> m;
  vector<int> t(m);
  rep(i, m) cin >> t[i];

  map<int, int> mp;
  rep(i, n) ++mp[d[i]];
  bool ok = true;
  rep(i, m) {
    if (mp[t[i]] == 0) {
      ok = false;
      break;
    }
    --mp[t[i]];
  }
  if (ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}