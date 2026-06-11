#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <map>

#define ll long long

using namespace std;

ll mod = 1e9 + 7;

void
solve() {
  ll n;
  cin>>n;

  vector<vector<ll>> a(n, vector<ll>(n, 0));
  for (ll i=0; i<n; i++)
    for (ll j=0; j<n; j++) 
      cin>>a[i][j];

  vector<ll> dp(1<<n, 0);
  dp[0] = 1;
  for (ll i=0; i<(1<<n); i++) {
    for (ll j=0; j<n; j++) {
      if ((i & (1 << j)) && a[j][__builtin_popcount(i)-1]) {
        dp[i] += dp[i - (1<<j)];
        dp[i] %= mod;
      }
    }
  }
  cout<<dp[(1<<n)-1]<<endl;
}

int
main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);

  ll t = 1;
  //cin>>t;

  while (t > 0) {
    t--;
    solve();
  }

  return 0;
}

