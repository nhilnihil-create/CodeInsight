#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;
  vector<int> v(26, 0);
  rep(i, 0, n) v[s[i] - 'a']++;

  ll ans = 1;
  rep(i, 0, 26) {
    if (v[i] > 0) {
      ans *= v[i] + 1;
      ans %= MOD;
    }
  }

  cout << ans - 1 << endl;
}
