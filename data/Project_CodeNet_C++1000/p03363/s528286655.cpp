#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n + 1);
  rep(i, n) {
    cin >> a[i];
    b[i + 1] = b[i] + a[i];
  }

  ll ans = 0;
  map<ll, ll> mp;
  rep(i, n + 1) {
    ans += mp[b[i]];
    mp[b[i]]++;
  }
  cout << ans << endl;
  return 0;
}
