#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> lb(n, 0); // 左からの黒の累積和
  vector<int> rw(n, 0); // 右からの白の累積和
  rep(i, n) {
    int tmp;
    if (i == 0) {
      tmp = 0;
    } else {
      tmp = lb.at(i - 1);
    }
    char c = s[i];
    if (c == '#') {
      tmp++;
    }
    lb.at(i) = tmp;
  }
  per(i, n) {
    int tmp;
    if (i == n - 1) {
      tmp = 0;
    } else {
      tmp = rw.at(i + 1);
    }
    char c = s[i];
    if (c == '.') {
      tmp++;
    }
    rw.at(i) = tmp;
  }
  // 白と黒の境目をすべて試す
  int res = INT_MAX;
  for (int i = 0; i <= n; i++) {
    int tmp = 0;
    // 黒を白にする数
    if (i != 0) {
      tmp += lb.at(i - 1);
    }
    // 白を黒にする数
    if (i != n) {
      tmp += rw.at(i);
    }
    res = min(res, tmp);
  }
  cout << res << endl;
  return 0;
}
