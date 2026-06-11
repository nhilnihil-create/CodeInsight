#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15);
  }
} initializer;

template<typename T> istream& operator>>(istream &s, vector<T> &v) {
  for (T &t : v) s >> t;
  return s;
}

template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
  for (const T &t : v) s << t << endl;
  return s;
}

int main() {
  int n;
  cin >> n;
  vector<int64_t> x(n), y(n), u(n), v(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  for (int i = 0; i < n; ++i) {
    u[i] = x[i] + y[i];
    v[i] = x[i] - y[i];
  }
  int o = 0, e = 0;
  for (int i = 0; i < n; ++i) {
    if (u[i] % 2) ++o;
    else ++e;
  }
  if (o && e) {
    cout << -1 << endl;
    return 0;
  }
  vector<int64_t> t;
  for (int64_t i = 1ll << 31; i; i /= 2) t.emplace_back(i);
  t.emplace_back(1);
  if (o) t.emplace_back(1);
  cout << t.size() << endl;
  for (int i = 0; i < int(t.size()); ++i) cout << t[i] << (i < int(t.size()) - 1 ? ' ' : '\n');
  vector<string> res(n);
  for (int i = 0; i < n; ++i) {
    for (auto j : t) {
      if (u[i] > 0) {
        if (v[i] > 0) res[i] += 'R';
        else res[i] += 'U';
      } else {
        if (v[i] > 0) res[i] += 'D';
        else res[i] += 'L';
      }
      if (u[i] > 0) u[i] -= j;
      else u[i] += j;
      if (v[i] > 0) v[i] -= j;
      else v[i] += j;
    }
  }
  cout << res;
}

