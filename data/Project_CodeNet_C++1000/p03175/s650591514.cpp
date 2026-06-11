#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

vector<vector<int>> adj;
vector<int> dp[2];

const int mod = 1e9 + 7;
enum Color {
  Black, White
};

int calc(int c, int u, int p) {
  if (dp[c][u] != -1) return dp[c][u];
  dp[c][u] = 1;
  for (auto to: adj[u]) {
    if (to == p) continue;
    if (c == Black) {
      dp[c][u] = dp[c][u] * 1ll * calc(White, to, u) % mod;
    } else {
      dp[c][u] = dp[c][u] * 1ll * (calc(White, to, u) + calc(Black, to, u)) % mod;
    }
  }
  return dp[c][u];
}
int main() {

  int n;
  cin >> n;
  int x, y;
  adj.resize(n);
  dp[Black].assign(n, -1);
  dp[White].assign(n, -1);
  for (int i = 0; i < n-1; ++i) {
    cin >> x >> y;
    adj[x-1].push_back(y-1);
    adj[y-1].push_back(x-1);
  }
  cout << (calc(Black, 0, 0) + calc(White, 0, 0)) % mod << '\n';
  return 0;
}
