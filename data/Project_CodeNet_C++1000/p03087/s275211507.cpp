#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

int main() {
  int n, q;
  string s;
  cin >> n >> q;
  cin >> s;

  vector<int> l(q), r(q);
  rep(i, q) cin >> l[i] >> r[i];

  int cnt = 0;
  vector<int> c(n + 1);
  rep(i, n - 1) {
    if (s.substr(i, 2) == "AC") ++cnt;
    c[i + 1] = cnt;
  }
  rep(i, q) {
    int ans = c[r[i] - 1] - c[l[i] - 1];
    printf("%d\n", ans);
  }
}
