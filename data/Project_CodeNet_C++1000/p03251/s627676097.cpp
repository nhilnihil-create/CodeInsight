#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

bool is_war(const vector<int>& x, const vector<int>& y) {
  for (int z = -100; z <= 100; z++) {
    bool is_ok = true;
    rep(i, 0, x.size()) if (x[i] >= z) is_ok = false;
    rep(i, 0, y.size()) if (y[i] < z) is_ok = false;
    if (is_ok) return false;
  }
  return true;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> x(N + 1), y(M + 1);
  cin >> x[0] >> y[0];
  rep(i, 0, N) cin >> x[i + 1];
  rep(i, 0, M) cin >> y[i + 1];

  if (is_war(x, y))
    cout << "War" << endl;
  else
    cout << "No War" << endl;

  return 0;
}
