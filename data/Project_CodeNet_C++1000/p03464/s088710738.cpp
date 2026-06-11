#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
using ll = long long;

int main() {
  ll l = 2, r = 3;
  int k;
  cin >> k;
  vector<int> a(k);
  rep(i,k) cin >> a[i];
  reverse(a.begin(), a.end());
  rep(i,k) {
    l = (l+a[i]-1) / a[i] * a[i];
    r = (r+a[i]-1) / a[i] * a[i];
  }
  if (r <= l) cout << -1 << endl;
  else cout << l << ' ' << r-1 << endl;
  return(0);
}