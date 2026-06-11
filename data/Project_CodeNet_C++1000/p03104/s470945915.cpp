#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// 0~nまでのi桁目に1は何回出てくるか
ll solve(ll n, ll i) {
  if (n == 0) {
    return 0;
  }

  // 0が何個続くか
  ll rep_0 = pow(2, i);
  ll dv = (n + 1) / (rep_0 * 2);
  ll md = (n + 1) % (rep_0 * 2);
  ll ans = dv * rep_0;
  if (md > rep_0) {
    ans += md - rep_0;
  }

  return ans;
}

int main(int argc, const char *argv[]) {
  ll a, b;
  cin >> a >> b;

  ll ans = 0;
  for (ll i = 0, pow2 = 1; i <= 40; ++i, pow2 *= 2) {
    ll cnt = solve(b, i) - solve(a - 1, i);
    ans += pow2 * (cnt % 2);
  }

  cout << ans << '\n';
}