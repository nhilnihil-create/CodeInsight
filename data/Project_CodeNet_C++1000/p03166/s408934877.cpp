#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 100005;

vector<int> G[N];

int dp[N];

int rec(int pos) {
  if (dp[pos] != -1) return dp[pos];
  int res = 0;
  rep(i, G[pos].size()) {
    int to = G[pos][i];
    res = max(res, rec(to) + 1);
  }
  return dp[pos] = res;
}

int main() {
  int n, m;
  cin >> n >> m;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    G[x].push_back(y);
  }
  rep(i, n) dp[i] = -1;
  int ans = 0;
  rep(i, n) ans = max(ans, rec(i));
  cout << ans << endl;
  return 0;
}