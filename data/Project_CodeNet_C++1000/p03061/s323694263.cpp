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
  cin >> n;
  vector<int> v(n), gcdasc(n, 0), gcddesc(n, 0);
  rep(i, 0, n) cin >> v[i];

  int b = v[0];
  gcdasc[0]=b;
  rep(i, 1, n) b = gcdasc[i] = __gcd(v[i], b);

  b = v[n-1];
  gcddesc[n-1]=b;
  repr(i, 0, n-1) b = gcddesc[i] = __gcd(v[i], b);

  int ans = max(gcddesc[1], gcdasc[n - 2]);

  rep(i, 1, n - 1) chmax(ans, __gcd(gcdasc[i - 1], gcddesc[i + 1]));

  cout << ans << endl;
}
