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
get(ll from, ll index, ll color, vector<vector<ll>> & link, vector<vector<ll>> & values) {
  if (values[index][color] == -1) {
    ll v = 1;
    for (auto p : link[index]) {
      if (p == from) continue;
      if (color == 1) 
        v *= get(index, p, 0, link, values);
      else 
        v *= (get(index, p, 0, link, values) + get(index, p, 1, link, values));
      v %= mod;
    }
    //cout<<index<<","<<color<<":"<<v<<endl;
    values[index][color] = v;
  }

  return values[index][color];
}

void
solve() {
  ll n;
  cin>>n;

  vector<vector<ll>> link(n+1, vector<ll>()), values(n+1, vector<ll>(2, -1));
  ll x, y;
  for (ll i=0; i<n-1; i++) {
    cin>>x>>y;
    link[x].push_back(y);
    link[y].push_back(x);
  }

  ll ans = (get(-1, 1, 0, link, values) + get(-1, 1, 1, link, values)) % mod;
  cout<<ans<<endl;
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

