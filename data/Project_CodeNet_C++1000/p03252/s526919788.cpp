#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  string t;
  cin >> s >> t;
  
  int n = s.size();
  vector<int> vs(n), vt(n);
  vector<int> ms(26, 0), mt(26, 0);
  int cs = 0, ct = 0;

  rep(i, n) {
    int si = s[i] - 'a';
    if (ms[si] == 0) ms[si] = ++cs;
    vs[i] = ms[si];

    int ti = t[i] - 'a';
    if (mt[ti] == 0) mt[ti] = ++ct;
    vt[i] = mt[ti];
  }
  bool ok = true;
  rep(i, n) if (vs[i] != vt[i]) ok = false;
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}