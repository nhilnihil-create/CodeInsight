#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, h;
  cin >> n >> h;

  vector<ll> vb(n), va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i] >> vb[i];
  }

  sort(vb.begin(), vb.end(), greater<ll>());
  sort(va.begin(), va.end(), greater<ll>());

  ll ans = 0;
  for (int i = 0; i < vb.size() && vb[i] >= va.front() && h > 0; i++) {
    h -= vb[i];
    ans++;
  }

  while (h > 0) {
    ans++;
    h -= va.front();
  }

  cout << ans << '\n';
  return 0;
}
