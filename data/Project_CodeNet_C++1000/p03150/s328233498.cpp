#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int n = s.size();
  string keys = "keyence";
  string l = "", r = "";
  rep(i, 0, keys.size()) {
    if (s[i] == keys[i])
      l += s[i];
    else
      break;
  }

  int c = keys.size();
  repr(i, (int)(n - keys.size()), n) {
    if (s[i] == keys[--c])
      r += s[i];
    else
      break;
  }
  reverse(r.begin(), r.end());

  vector<bool> true_count(7, false);
  rep(i, 0, l.size()) {
    if (keys[i] = l[i])
      true_count[i] = true;
  }

  int rs = r.size() - 1;
  repr(i, (int)(keys.size() - r.size()), keys.size()) {
    true_count[i] = r[rs];
    rs--;
  }

  rep(i, 0, keys.size()) {
    if (!true_count[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}