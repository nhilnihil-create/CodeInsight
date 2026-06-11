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

  int n;
  string s;
  cin >> n >> s;

  string l = "", r = s;
  int ans = 0;
  rep(i, 0, n) {
    vector<int> lv(26, 0), rv(26, 0);
    rep(j, 0, (int)l.size()) lv[l[j] - 'a']++;
    rep(j, 0, (int)r.size()) rv[r[j] - 'a']++;
    int c = 0;
    rep(j, 0, 26) if (lv[j] && rv[j]) c++;
    chmax(ans, c);
    l += r[0];
    r = r.substr(1);
  }

  cout << ans << endl;
}
