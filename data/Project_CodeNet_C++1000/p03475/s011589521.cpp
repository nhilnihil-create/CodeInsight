#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> c(n-1), s(n-1), f(n-1);
  rep(i, n-1) cin >> c[i] >> s[i] >> f[i];

  vector<int> res(n, 0);

  rep(si, n) {
    for (int i = si; i < n-1; ++i) {
      if (res[si] < s[i]) res[si] = s[i];
      if (res[si] % f[i]) res[si] += f[i] - res[si] % f[i];
      res[si] += c[i];
    }
  }

  rep(si, n) cout << res[si] << endl;
  return 0;
}