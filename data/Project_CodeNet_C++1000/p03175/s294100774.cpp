#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

const ll N = 2 * 1e5, MOD = 1e9 + 7;

vector <int> edges[N], children[N];
ll dp[N][2];

ll numberOfWays(ll curr, int parentColor) {
  if (dp[curr][parentColor])
    return dp[curr][parentColor];

  ll ans = 0, localAns = 1;

  for (int i = 0; i < (int)children[curr].size(); i++)
    localAns *= numberOfWays(children[curr][i], !parentColor) % MOD, localAns %= MOD;
  
  ans += localAns % MOD;
  localAns = 1;

  if (!parentColor) {
    for (int i = 0; i < (int)children[curr].size(); i++)
      localAns *= numberOfWays(children[curr][i], parentColor) % MOD, localAns %= MOD;
    ans += localAns % MOD;
  }
  
  return dp[curr][parentColor] = (ans % MOD);
}

void dfs(int node, int parent) {
  for (int i = 0; i < (int)edges[node].size(); i++)
    if (edges[node][i] != parent) {
      children[node].push_back(edges[node][i]);
      dfs(edges[node][i], node);
    }
}

int main() {
  int n, x, y;
  cin >> n;

  for (int i = 0; i < n-1; i++) {
    cin >> x >> y;
    x--, y--;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }

  dfs(0, -1);
  cout << (numberOfWays(0, 0) % MOD) << endl;
}
