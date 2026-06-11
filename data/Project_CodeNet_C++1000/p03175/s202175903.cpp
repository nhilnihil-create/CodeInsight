/*
ID: varunra2
LANG: C++
TASK: p
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "lib/debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define debug_arr(...) \
  cerr << "[" << #__VA_ARGS__ << "]:", debug_arr(__VA_ARGS__)
#pragma GCC diagnostic ignored "-Wsign-compare"
//#pragma GCC diagnostic ignored "-Wunused-parameter"
//#pragma GCC diagnostic ignored "-Wunused-variable"
#else
#define debug(...) 42
#endif

#define EPS 1e-9
#define IN(A, B, C) assert(B <= A && A <= C)
#define INF (int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define x first
#define y second

const double PI = acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef map<int, int> MPII;
typedef multiset<int> MSETI;
typedef set<int> SETI;
typedef set<string> SETS;
typedef vector<ll> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
#pragma GCC diagnostic ignored "-Wsign-compare"
// util functions

VVI dp;
VVI adj;
int n;

void dfs(int u, int v) {
  for (auto& x : adj[u]) {
    if (x == v) continue;
    dfs(x, u);
  }
  dp[u][0] = 1;
  dp[u][1] = 1;
  // first we calc 0 -> black
  for (auto& x : adj[u]) {
    if (x == v) continue;
    dp[u][0] *= dp[x][1];
    dp[u][0] %= MOD;
  }

  // now we calc 1 -> white

  for (auto& x : adj[u]) {
    if (x == v) continue;
    ll sm = dp[x][0] + dp[x][1];
    dp[u][1] *= sm;
    dp[u][1] %= MOD;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("p.in", "r", stdin);
  freopen("p.out", "w", stdout);
#endif
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  dp.resize(n);
  adj.resize(n);

  for (int i = 0; i < n; i++) {
    dp[i].resize(2);
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  dfs(0, -1);

  cout << (dp[0][0] + dp[0][1]) % MOD << endl;

  return 0;
}
