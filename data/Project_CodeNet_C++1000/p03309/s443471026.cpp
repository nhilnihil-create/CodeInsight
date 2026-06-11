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
  vector<ll> a(n), v(n);
  rep(i, 0, n) {
    cin >> a[i];
    v[i] = a[i] - (i + 1);
  }

  vector<ll> sv = v;
  sort(sv.begin(), sv.end());
  int mid = n / 2;
  int add1 = 0, add2 = 0;
  if (sv[mid] > 0)
    add1 = -sv[mid];

  if (n % 2 == 0)
    mid--;
  if (sv[mid] < 0)
    add2 = -sv[mid];

  ll ans1 = 0, ans2 = 0;
  rep(i, 0, n) ans1 += abs(v[i] + add1);
  rep(i, 0, n) ans2 += abs(v[i] + add2);

  cout << min(ans1, ans2) << endl;
}
