#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n, m, b, c, ans = 0;
  cin >> n >> m;

  map<ll, ll> p;
  vector<ll> a(n + m + 5);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[a[i]]++;
  }

  for (int i = n; i < n + m; i++) {
    cin >> b >> a[i];
    p[a[i]] += b;
  }

  sort(a.rbegin(), a.rend());

  int cnt = 0, i = 0;

  for (int i = 0; i < n; i++) {
    if (cnt + p[a[i]] < n) {
      ans += a[i] * p[a[i]];
      cnt += p[a[i]];
      p[a[i]] = 0;
    } else if (cnt + p[a[i]] >= n) {
      ans += a[i] * (n - cnt);
      cout << ans << endl;
      return 0;
    }
  }
}