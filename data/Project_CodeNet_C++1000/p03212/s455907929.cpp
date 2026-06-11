#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int n;
int ans = 0;
void dfs(int i, string s, bool thr, bool fiv, bool sev) {
  if (i && stol(s) > n)
    return;
  else {
    if (thr && fiv && sev)
      ans++;
  }

  ll res = 0;
  if (stol(s + "3") <= n)
    dfs(i + 1, s + "3", true, fiv, sev);
  if (stol(s + "5") <= n)
    dfs(i + 1, s + "5", thr, true, sev);
  if (stol(s + "7") <= n)
    dfs(i + 1, s + "7", thr, fiv, true);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  dfs(0, "", false, false, false);
  cout << ans << endl;
}
