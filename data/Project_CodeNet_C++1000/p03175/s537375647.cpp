#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int MAXN = 100003;
const int STATES = 2;

int N;
vector<int> edges[MAXN];
int dp[MAXN][STATES];

int add(int a, int b) {
  return (a + b) % MOD;
}
int mul(int a, int b) {
  return (ll(a) * ll(b)) % MOD;
}
int solve(int u, int parent, bool black) {
  if(parent > 0 && edges[u].size() == 1) return 1;
  if(dp[u][black]) return dp[u][black];

  int ans = 1;
  if(black) {
    for(int v: edges[u]) {
      if(v == parent) continue;

      ans = mul(ans, solve(v, u, 0));
    }
  } else {
    for(int v: edges[u]) {
      if(v == parent) continue;

      ans = mul(ans, add(solve(v, u, 0), solve(v, u, 1)));
    }
  }
  
  return dp[u][black] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for(int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int ans = add(solve(1, -1, 0), solve(1, -1, 1));
  cout << ans << "\n";
  return 0;
}
