#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  cout << "}";
  return os;
}

// ====================================================================

int main() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) { cin >> v[i]; }

  ll ans = 0, right = 0, gokei = 0, xsum = 0;
  for (ll left = 0; left < n; left++) {
    while (right < n && ((gokei + v[right]) == (xsum ^ v[right]))) {
      gokei += v[right];
      xsum ^= v[right];
      right++;
    }
    ans += right - left;  // 足す
    gokei -= v[left];
    xsum ^= v[left];
  }

  cout << ans << endl;
}
