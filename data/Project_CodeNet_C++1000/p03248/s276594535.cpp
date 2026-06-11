#include <random>
#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld eps = 1e-12;
constexpr int inf = numeric_limits<int>::max() / 2;
constexpr ll mod = 1e9 + 7;
mt19937_64 rnd{random_device()()};

template <typename T>
void printv(const vector<T> &v) {
  int sz = v.size();
  for (int i = 0; i < sz; i++) {
    cout << v[i] << " \n"[i == sz - 1];
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int n = s.size();
  s = "$" + s;
  if (s[1] == '0' || s[n] == '1') {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] != s[n - i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  vector<int> pos;
  for (int i = 1; i <= n / 2; i++) {
    if (s[i] == '1') pos.push_back(i);
  }
  pos.push_back(n);
  int sz = pos.size();
  for (int i = 0; i < sz - 1; i++) {
    int u = pos[i], v = pos[i + 1];
    cout << u << " " << v << endl;
    for (int j = u + 1; j < v; j++) {
      cout << j << " " << v << endl;
    }
  }
}
