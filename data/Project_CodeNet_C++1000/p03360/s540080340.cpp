#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  vector<ll> d(3);
  ll k;
  rep(i, 3) cin >> d[i];
  cin >> k;
  sort(d.rbegin(), d.rend());
  rep(i, k) d[0] *= 2;
  cout << d[0] + d[1] + d[2] << endl;
  return 0;
}
