#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(i, n) {
    vector<int> x(26, 0), y(26, 0);
    rep(j, i) x[s[j] - 'a'] = 1;
    for (int j = i; j < n; ++j) y[s[j] - 'a'] = 1;
    int c = 0;
    rep(j, 26) if (x[j] * y[j] == 1) ++c;
    ans = max(ans, c);
  }
  cout << ans << endl;
  return 0;
}