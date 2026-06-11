#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> A(x), B(y), C(z);
  rep(i, x) cin >> A[i];
  rep(i, y) cin >> B[i];
  rep(i, z) cin >> C[i];
  int n = x * y;
  vector<ll> D(n);
  rep(i, x) rep(j, y) D[i+j*x] = A[i] + B[j];
  sort(D.begin(), D.end());

  auto f = [&](ll c) {
    int res = D.end() - lower_bound(D.begin(), D.end(), c);
    return res;
  };

  auto g = [&](ll c) {
    int res = 0;
    rep(i, z) {
      res += f(c - C[i]);
    }
    return res;
  };

  ll l = 0, r = 10000000000 * 3 + 1;
  while (l+1 < r) {
    ll m = (l+r) / 2;
    if (k > g(m)) r = m;
    else l = m;
  }

  vector<ll> ans;
  rep(i, z) {
    rep(j, n) {
      if (C[i] + D[n-1-j] < r) break;
      ans.push_back(C[i] + D[n-1-j]);
    }
  }
  sort(ans.rbegin(), ans.rend());
  for (ll a : ans) cout << a << endl;
  rep(i, k-ans.size()) cout << l << endl;
  
  return 0;
}
