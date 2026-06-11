#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int n, ans = 0;
void dfs(string s) {

  if (s != "") {
    ll x = stol(s);
    if (x > n)
      return;

    vector<int> ok(10, 0);
    rep(i, 0, (int)s.size()) { ok[s[i] - '0']++; }
    if (ok[3] && ok[5] && ok[7])
      ans++;
  }

  dfs(s + "3");
  dfs(s + "5");
  dfs(s + "7");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  dfs("");
  cout << ans << endl;
}
