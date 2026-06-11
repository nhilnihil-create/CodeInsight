#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll dp[410][410], v[410][410], b[410];

ll f(int l, int r) {
  if (l == r) return 0;
  if (v[l][r]) return dp[l][r];
  v[l][r] = 1;
  ll res = 1e18;
  for (int i = l; i < r; ++i)
    res = min(res, f(l, i) + f(i + 1, r) + b[r + 1] - b[l]);

  return dp[l][r] = res;
}

int main() {
  ll n, ans = 0;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) b[i + 1] = b[i] + a[i];

  cout << f(0, n - 1) << endl;
  return 0;
}