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
  ll n, k;
  cin>>n>>k;

  vector<ll> a(n);
  for (ll i=0; i<n; i++) cin>>a[i];

  vector<vector<ll>> dp(n, vector<ll>(k+1, 0));
  for (ll i=0; i<n; i++) {
    if (i==0) {
      for (ll j=0; j<=a[i]; j++)
        dp[i][j] = 1;
    }
    else {
      queue<ll> data;
      ll now = 0;
      for (ll j=0; j<=k; j++) {
        data.push(dp[i-1][j]);
        now += dp[i-1][j];
        now %= mod;
        if (j > a[i]) {
          now -= data.front();
          now %= mod;
          now += mod;
          now %= mod;
          data.pop();
        }
        dp[i][j] = now;
        //cout<<i<<","<<j<<":"<<now<<endl;
      }
    }
  }

  cout<<dp[n-1][k]<<endl;
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

