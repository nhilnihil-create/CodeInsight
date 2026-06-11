#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  //
  ll n, h, w;
  cin >> n >> h >> w;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    if (a >= h && b >= w) {
      ans++;
    }
  }

  cout << ans << '\n';
}