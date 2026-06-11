#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll A; cin >> A;
  ll B; cin >> B;
  ll C; cin >> C;
  ll X; cin >> X;
  ll Y; cin >> Y;


  ll ans = 1e15;
  for (int i = 0; i <= max(X * 2,Y * 2); i++) {
    ll temp = C * i;
    ll a = max(X - i / 2, 0ll) * A;
    ll b = max(Y - i / 2, 0ll) * B;
    ans = min(ans, temp + a + b);
  }

  cout << ans << '\n';
  return 0;
}