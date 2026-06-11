#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;
constexpr int MAXN = 3005;

int n;
string s;

ll dp[MAXN][MAXN];
ll pre[MAXN][MAXN];

// number of permutations of {0..i} with last number j
// dp[i][j] =
//   if (s[i - 1] is '<')
//     sum dp[i - 1][k] for k < j
//     basically increment everything less than k in each sub-perm by 1
//   else
//     sum dp[i - 1][k] for k >= j
//     basically decrement everything less than k in each sub-perm by 1
ll solve(int i, int j) {
  if (i == 0) { return (j == 0) ? 1 : 0; }
  if (j < 0) { return 0; }
  ll& res = dp[i][j];
  if (res != -1) { return res; }
  res = 0;
  if (s[i - 1] == '<') {
    for (int k = 0; k < j; k++) {
      res += solve(i - 1, k);
      res %= MOD;
    }
  } else {
    for (int k = j; k < i; k++) {
      res += solve(i - 1, k);
      res %= MOD;
    }
  }
  return res;
}

ll solve_fast(int i, int j);

void prefill(int i) {
  if (dp[i][0] != -1) { return; }
  for (int j = 0; j < n; j++) {
    pre[i][j] = solve_fast(i, j);
  }
  for (int j = 1; j < n; j++) {
    pre[i][j] += pre[i][j - 1];
    pre[i][j] %= MOD;
  }
}

ll getsum(int i, int j0, int j1) {
  ll res = pre[i][j1];
  if (j0 > 0) {
    res += MOD - pre[i][j0 - 1];
    res %= MOD;
  }
  return res;
}

ll solve_fast(int i, int j) {
  if (i == 0) { return (j == 0) ? 1 : 0; }
  if (j < 0) { return 0; }
  ll& res = dp[i][j];
  if (res != -1) { return res; }
  prefill(i - 1);
  res = 0;
  if (s[i - 1] == '<') {
    res = getsum(i - 1, 0, j - 1);
  } else {
    res = getsum(i - 1, j, i - 1);
  }
  return res;
}

int main() {
  fill(dp[0], dp[0] + MAXN * MAXN, -1LL);
  cin >> n >> s;
  ll res = 0;
  for (int j = 0; j < n; j++) {
    res += solve_fast(n - 1, j);
    res %= MOD;
  }
  cout << res << '\n';
  return 0;
}
