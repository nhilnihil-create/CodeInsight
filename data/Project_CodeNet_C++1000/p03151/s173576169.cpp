#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, ans = 0, sum = 0, num = 0, tot = 0;
  cin >> n;
  vector<ll> a(n), b(n), p;
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  rep(i, n) {
    ll d = a[i] - b[i];
    tot += d;
    if (d < 0)
      sum += d, num++;
    else
      p.push_back(d);
  }

  if (tot < 0) {
    puts("-1");
    return 0;
  }

  sort(p.rbegin(), p.rend());

  if (sum < 0) {
    rep(i, p.size()) {
      sum += p[i];
      num++;
      if (sum >= 0) break;
    }
  }

  cout << num << endl;
  return 0;
}
