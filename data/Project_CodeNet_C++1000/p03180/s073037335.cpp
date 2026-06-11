#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  int total_sz = (1 << n);
  vector<ll> group_sum(total_sz, 0), f(total_sz, 0);
  for (int mask = 0; mask < total_sz; ++mask) {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      if (mask >> i & 1) {
        v.push_back(i);
      }
    }
    ll score = 0;
    int sz = v.size();
    for (int i = 0; i < sz; ++i) {
      for (int j = i + 1; j < sz; ++j) {
        score += a[v[i]][v[j]];
      }
    }
    f[mask] = group_sum[mask] = score;
  }

  for (int mask = 0; mask < total_sz; ++mask) {
    for (int submask = mask; submask; submask = (submask-1) & mask) {
      f[mask] = max(f[mask], f[mask ^ submask] + group_sum[submask]);
    }
  }
  cout << f[total_sz-1] << '\n';
  return 0;
}
