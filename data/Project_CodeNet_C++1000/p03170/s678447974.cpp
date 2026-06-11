#ifdef ONLINE_JUDGE
  #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#endif

#include "bits/stdc++.h"
using namespace std;
#define int long long
#define ld long double
#define mtr vector<vector<int>>

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))

int dp[1000010], n, k;
vector<int> v;

int solve(int x) {
  if (dp[x]) return dp[x];
  for (int i = 0; i < n; i ++) {
    if (v[i] <= x) {
      if (solve(x - v[i]) == 2) {
        return dp[x] = 1;
      }
    }
  }
  return dp[x] = 2;
}

signed main() {
  #ifndef ONLINE_JUDGE
    ifstream cin("in");
  #endif
  ios_base::sync_with_stdio(0); cin.tie(0); // harris leung ioi gold calling it 18.09

  cin >> n >> k;
  for (int i = 0; i < n; i ++) {
    int l; cin >> l; v.push_back(l);
  }
  dp[0] = 2;
  cout << (solve(k) == 1 ? "First" : "Second") << endl;
}