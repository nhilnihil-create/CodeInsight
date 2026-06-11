#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  string s;
  vector<pair<string, string>> ops;

  cin >> n >> q >> s;
  ops.resize(q);

  for (int i = 0; i < q; i++) {
    cin >> ops[i].first >> ops[i].second;
  }

  auto get = [&] (int pos) {
    for (int i = 0; i < q; i++) {
      if (ops[i].first[0] == s[pos]) {
        if (ops[i].second == "L") {
          pos--;
        } else {
          pos++;
        }
        if (pos < 0) {
          return -1;
        }
        if (pos >= n) {
          return +1;
        }
      }
    }
    return 0;
  };

  int alpha = 0, beta = 0, l = 0, r = n - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (get(m) == -1) {
      alpha = m + 1;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  l = 0;
  r = n - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (get(m) == +1) {
      beta = n - m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << n - alpha - beta << "\n";
}
