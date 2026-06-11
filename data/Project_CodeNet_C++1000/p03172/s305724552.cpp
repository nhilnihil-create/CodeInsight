#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int n, k;
vector<int> a;
vector<vector<int>> dp;

int solve(int x, int rem) {
  if (rem < 0) return 0;
  if (x < 0) return 1;

  int &ret = dp[x][rem];
  if (ret != -1) return ret;

  ret = solve(x, rem - 1);
  ret += solve(x-1, rem) - solve(x-1, rem - a[x] - 1);
  ret %= M;
  if (ret < 0) ret += M;
  return ret;
};

int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> n >> k;
  a.resize(n);
  dp.resize(n, vector<int> (k + 1, -1));

  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << (solve(n - 1, k) - solve(n - 1, k - 1) + M) % M << '\n';
}
