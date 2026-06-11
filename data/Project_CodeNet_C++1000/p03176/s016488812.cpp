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

ll
getValue(vector<ll> & seg, ll start, ll end) {
  if (start > end) return 0;

  ll ret = 0;
  while (1) {
    if (start > end) break;

    if (end % 2 == 0) {
      ret = max(ret, seg[end]);
      end--;
    }
    if (start % 2 == 1) {
      ret = max(ret, seg[start]);
      start++;
    }

    start /= 2;
    end /= 2;
  }

  return ret;
}

void
update(vector<ll> & seg, ll index, ll v) {
  ll i = index;
  seg[i] = v;
  while (1) {
    if (i == 0) break;

    i /= 2;
    seg[i] = max(seg[i*2], seg[i*2+1]);
  }
}

void
solve() {
  ll n;
  cin>>n;

  vector<ll> h(n), a(n);
  for (ll i=0; i<n; i++) { cin>>h[i]; h[i]--; }
  for (ll i=0; i<n; i++) cin>>a[i];

  vector<ll> seg(2 * n, 0);
  ll ans = 0;
  for (ll i=0; i<n; i++) {
    ll v = getValue(seg, n, h[i]+n-1) + a[i];
    ans = max(ans, v);
    update(seg, h[i]+n, v);

    //for (ll i=0; i<2*n; i++) cout<<seg[i]<<","; cout<<endl;
  }
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

