#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n, x, total = 0;
  cin >> n >> x;
  vector<int> m(n);
  rep(i, n) {
    cin >> m[i];
    total += m[i];
  }
  x -= total;
  sort(m.begin(), m.end());
  cout << n + x / m[0] << endl;
  return 0;
}
