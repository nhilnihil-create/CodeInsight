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

ll
get(vector<vector<ll>> & dp, ll start, ll end, vector<ll> & a, vector<ll> & sum) {
  if (start >= end) return 0;

  if (dp[start][end] == -1) {
    ll v = get(dp, start + 1, end, a, sum);
    for (ll right = start + 1; right < end; right++) 
      v = min(v, get(dp, start, right, a, sum) + get(dp, right+1, end, a, sum));
    dp[start][end] = v + sum[end] - sum[start-1];
  }

  return dp[start][end];
}

void
solve() {
  ll n;
  cin>>n;

  vector<ll> a(n+1), sum(n+1, 0);
  for (ll i=1; i<=n; i++) {
    cin>>a[i];
    sum[i] = sum[i-1] + a[i];
  }

  vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1));
  cout<<get(dp, 1, n, a, sum)<<endl;
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

