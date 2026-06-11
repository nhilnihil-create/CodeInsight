#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int64 c;
  cin >> n >> c;
  vector<int64> xs(n + 1);
  for (int i = 1; i <= n; i++) cin >> xs[i];
  vector<int64> cumulated_xs(n + 1);
  for (int i = 1; i <= n; i++) cumulated_xs[i] = cumulated_xs[i - 1] + xs[i];

  int64 max_cost = 2 * n * c + 5 * cumulated_xs[n];
  auto solve_for_k = [&](int k) {
    int64 cost = (n + k) * c;
    // cout << "cost : " << cost << endl;
    
    int r = n;
    int64 unit_cost = 5;
    while (r > 0) {
      int l;
      if (unit_cost == 5) {
        l = max(r - 2 * k, 0);
      } else {
        l = max(r - k, 0);
      }
      cost += (cumulated_xs[r] - cumulated_xs[l]) * unit_cost;
      if (cost > max_cost) return max_cost;
      r = l;
      unit_cost += 2;
    }
    // cout << "k: " << k << " cost: " << cost << endl;
    return cost;
  };

  int64 ans = max_cost;
  for (int k = 1; k <= n; k++) {
    UpdateMin(ans, solve_for_k(k));
  }
  cout << ans << endl;
}
