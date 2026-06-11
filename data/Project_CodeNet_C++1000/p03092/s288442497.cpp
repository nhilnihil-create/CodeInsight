// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
#include<bitset>
#include<cstdlib>
// #include<deque>
// #include<multiset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

int n;
ll a, b;
int p[5000];

ll dp[5001][5001];

// smin, smax {{{
template < class T, class U >
inline void smin(T &a, const U &b) {
  a = a < (T) b ? a : b;
}
template < class T, class U >
inline void smax(T &a, const U &b) {
  a = a < (T) b ? b : a;
}
// }}}

constexpr ll inf = 1e18;
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  cin >> n >> a >> b;
  for(int i = 0; i < n; i++) cin >> p[i];
  for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) dp[i][j] = inf;
 
  dp[0][0] = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= n; j++) {
      if(j < p[i]) {
        smin(dp[i + 1][p[i]], dp[i][j]);
        smin(dp[i + 1][j], dp[i][j] + a);
      } else {
        smin(dp[i + 1][j], dp[i][j] + b);
      }
    }
  }

  ll ans = inf;

  for(int j = 0; j <= n; j++) smin(ans, dp[n][j]);

  cout << ans << endl;

  return 0;
}
