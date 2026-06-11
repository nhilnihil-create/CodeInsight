#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &costs, int a, vector<int> &memo) {
  if (a <= 0) {
    return a == 0 ? 0 : -20000;
  }

  if (memo[a] == -1) {
    int ans = solve(costs, a - costs[0], memo) + 1;
    for (int i = 0; i < costs.size(); i++) {
      ans = max(ans, solve(costs, a - costs[i], memo) + 1);
    }

    memo[a] = ans;
  }

  return memo[a];
}

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<int> all_costs{2, 5, 5, 4, 5, 6, 3, 7, 6};
  vector<int> va(m);
  for (int i = 0; i < m; ++i) {
    cin >> va[i];
  }

  sort(va.begin(), va.end(), greater<int>());

  vector<int> costs;
  for (auto a : va) {
    costs.push_back(all_costs[a - 1]);
  }

  vector<int> memo(n + 1, -1);

  int max_d = solve(costs, n, memo);

  string ans;
  int r = n;
  for (int i = 1; i <= max_d; i++) {
    for (int j = 0; j < costs.size(); ++j) {
      int d = solve(costs, r - costs[j], memo);
      if (d == max_d - i) {
        ans += to_string(va[j]);
        r -= costs[j];
        break;
      }
    }
  }

  cout << ans << '\n';
}