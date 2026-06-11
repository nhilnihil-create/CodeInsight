#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  int m;
  cin >> m;
  vector<string> t(m);
  rep(i, m) cin >> t[i];
  
  map<string, int> b, r;
  rep(i, n) ++b[s[i]];
  rep(i, m) ++r[t[i]];

  int x = 0;
  rep(i, n) x = max(x, b[s[i]] - r[s[i]]);
  rep(i, m) x = max(x, b[t[i]] - r[t[i]]);
  cout << x << endl;
  return 0;
}