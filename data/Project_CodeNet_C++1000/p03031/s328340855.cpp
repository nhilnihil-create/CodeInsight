#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> v(m);
  rep(i, 0, m) {
    int k;
    cin >> k;
    rep(j, 0, k) {
      int s;
      cin >> s;
      s--;
      v[i].push_back(s);
    }
  }

  vector<int> p(m);
  rep(i, 0, m) cin >> p[i];

  int ans = 0;
  rep(i, 0, 1 << n) {
    vector<int> swi(n, 0);
    rep(j, 0, n) {
      if (i >> j & 1) {
        swi[j] = 1;
      }
    }

    bool b = true;
    rep(j, 0, m) {
      int c = 0;
      rep(k, 0, v[j].size()) { c += swi[v[j][k]]; }
      if (c % 2 != p[j]) {
        b = false;
        break;
      }
    }

    if (b)
      ans++;
  }

  cout << ans << endl;
}
