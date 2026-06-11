#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> t(n + 1), x(n + 1), y(n + 1);
  t[0] = 0;
  x[0] = 0;
  y[0] = 0;
  rep(i, n) cin >> t[i + 1] >> x[i + 1] >> y[i + 1];

  bool able = true;
  rep(i, n) {
    int dx = abs(x[i + 1] - x[i]);
    int dy = abs(y[i + 1] - y[i]);
    int dt = t[i + 1] - t[i];
    if (dt < dx + dy || dt % 2 != (dx + dy) % 2) able = false;
  }
  if (able) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}