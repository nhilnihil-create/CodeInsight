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
  vector<bool> v(26, false);

  if (n == 26) {
    v[s[n - 1] - 'a'] = true;
    repr(i, 0, n - 1) {
      int t = s[i] - 'a';
      rep(j, t, 26) {
        if (v[j]) {
          cout << s.substr(0, i) << (char)(j + 'a') << endl;
          return 0;
        }
      }
      v[s[i] - 'a'] = true;
    }
    cout << -1 << endl;
  } else {
    rep(i, 0, n) v[s[i] - 'a'] = true;
    rep(i, 0, 26) {
      if (!v[i]) {
        cout << s << (char)(i + 'a') << endl;
        return 0;
      }
    }
  }
}
