/*
ID: varunra2
LANG: C++
TASK: matchings
*/

#include<bits/stdc++.h>
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
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
#pragma GCC diagnostic ignored "-Wsign-compare"
// util functions

int n;
VVI grid;
VI dp;

void init() {
  dp.resize(1 << n);
  grid.resize(n);
  for(int i = 0; i < n; i++) grid[i].resize(n);
  rep(i, 0, sz(dp)) dp[i] = 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("matchings.in", "r", stdin);
  freopen("matchings.out", "w", stdout);
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  cin >> n;

  init();

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  dp[0] = 1;
  for(int i = 1; i < (1 << n); i++) {
    int cur = __builtin_popcount(i) - 1;
    for(int j = 0; j < n; j++) {
      if(grid[cur][j] == 0) continue;
      if(i & (1 << j)) {
        dp[i] += dp[i - (1 << j)];
        if(dp[i] >= MOD) dp[i] -= MOD;
      }
    }
  }

  cout << dp[(1 << n) - 1] << '\n';

  return 0;
}
