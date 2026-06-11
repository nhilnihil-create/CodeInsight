#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = INT_MAX;
const int MOD = 1000000007;
const long long INF = LLONG_MAX;

// -------------------------------------------------------

ll N;
vector<ll> Graph[101010];

ll dp[101010][2];

ll dfs(ll n, ll par, ll color) {
  if (dp[n][color] != -1) {
    return dp[n][color];
  }

  if ((Graph[n].size() == 1 && Graph[n][0] == par) || Graph[n].size() == 0) {
    return dp[n][color] = 1;
  }

  ll res = 1;
  for (auto e : Graph[n]) {
    if (e != par) {
      ll sum = 0;
      sum += dfs(e, n, 0);
      sum %= MOD;
      if (color == 0) {
        sum += dfs(e, n, 1);
        sum %= MOD;
      }
      res *= sum;
      res %= MOD;
    }
  }
  return dp[n][color] = res;
}

int main() {
  cin >> N;
  rep(i, 0, N - 1) {
    ll x, y;
    cin >> x >> y;
    Graph[x].push_back(y);
    Graph[y].push_back(x);
  }

  rep(i, 0, 101010) {
    rep(j, 0, 2) { dp[i][j] = -1; }
  }

  cout << (dfs(1, 0, 0) + dfs(1, 0, 1)) % MOD;
}
