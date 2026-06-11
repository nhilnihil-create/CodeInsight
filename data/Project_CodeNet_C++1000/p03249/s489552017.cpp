#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<long long, int>> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i].first;
    d[i].second = i;
  }
  sort(d.begin(), d.end());
  vector<pair<int, int>> ans;
  vector<long long> sum(n);
  vector<int> sz(n, 1);
  for (int i = n - 1; i; --i) {
    long long v = d[i].first - n + 2 * sz[i];
    int p = lower_bound(d.begin(), d.end(), make_pair(v, 0)) - d.begin();
    if (p == n || d[p].first != v) {
      cout << -1 << "\n";
      return 0;
    }
    sum[p] += sum[i] + sz[i];
    sz[p] += sz[i];
    ans.emplace_back(d[i].second, d[p].second);
  }
  if (sum[0] != d[0].first) {
    cout << -1 << "\n";
    return 0;
  }
  for (auto p : ans) {
    cout << p.first + 1 << " " << p.second + 1 << "\n";
  }
  return 0;
}
