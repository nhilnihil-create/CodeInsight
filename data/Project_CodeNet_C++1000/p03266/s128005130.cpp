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

  int n, k;
  cin >> n >> k;
  vector<ll> num(k, 0);
  rep(i, 1, n + 1) num[i % k]++;

  ll ans = 0;
  rep(a, 0, k) {
    int b = (k - a) % k;
    int c = (k - a) % k;
    if ((b + c) % k != 0)
      continue;
    ans += num[a] * num[b] * num[c];
  }

  cout << ans << endl;
}
