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
#include <iomanip>

#define ll long long

using namespace std;

double dp[301][301][301];
bool vis[301][301][301];

double
get(ll n, ll a, ll b, ll c) {
  if (!vis[a][b][c]) {
    double v = 0;
    if (a == 0 && b == 0 && c == 0) {
      v = 0;
    }
    else {
      v = n - a - b - c;
      if (a > 0) v += (get(n, a-1, b, c) + 1) * a;
      if (b > 0) v += (get(n, a+1, b-1, c) + 1) * b;
      if (c > 0) v += (get(n, a, b+1, c-1) + 1) * c;
      v /= a + b + c;
    }

    dp[a][b][c] = v;
    vis[a][b][c] = true;
  }

  return dp[a][b][c];
}

void
solve() {
  ll n;
  cin>>n;

  ll a = 0, b = 0, c = 0;
  ll x;
  for (ll i=0; i<n; i++) {
    cin>>x;
    if (x == 1)
      a++;
    else if (x == 2)
      b++;
    else if (x == 3)
      c++;
  }

  cout<<fixed<<setprecision(15)<<get(n, a, b, c)<<endl;
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

