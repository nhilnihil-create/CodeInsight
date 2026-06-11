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
  int n = (int)s.size();

  ll ac = 0, ans = 0;
  rep(i, 0, n - 2) {
    if (s[i] == 'A')
      ac++;
    else
      ac = 0;

    if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
      ans += ac;
      ac--;
      s[i + 2] = 'A';
      i++;
    }
  }

  cout << ans << endl;
}
