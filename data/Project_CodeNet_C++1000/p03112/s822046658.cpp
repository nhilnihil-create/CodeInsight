#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  int a, b, q;
  scanf("%d %d %d", &a, &b, &q);
  vector<ll> s(a), t(b), o(q), is(a), it(b), st(a, LONG_LONG_MAX),
      ts(b, LONG_LONG_MAX);
  for(int i = 0; i < a; i++) {
    scanf("%lld", &s[i]);
    is[a - 1 - i] = -s[i];
  }
  for(int i = 0; i < b; i++) {
    scanf("%lld", &t[i]);
    it[b - 1 - i] = -t[i];
    auto itfw = upper_bound(s.begin(), s.end(), t[i]),
         itba = upper_bound(is.begin(), is.end(), -t[i]);
    if(itfw != s.end()) ts[i] = min(ts[i], *itfw - t[i]);
    if(itba != is.end()) ts[i] = min(ts[i], *itba + t[i]);
  }
  for(int i = 0; i < a; i++) {
    auto itfw = upper_bound(t.begin(), t.end(), s[i]),
         itba = upper_bound(it.begin(), it.end(), -s[i]);
    if(itfw != t.end()) st[i] = min(st[i], *itfw - s[i]);
    if(itba != it.end()) st[i] = min(st[i], *itba + s[i]);
  }
  for(int i = 0; i < q; i++) {
    ll x, m = LONG_LONG_MAX;
    scanf("%lld", &x);
    int sb = -distance(is.end(), upper_bound(is.begin(), is.end(), -x)) - 1,
        sf = distance(s.begin(), upper_bound(s.begin(), s.end(), x)),
        tb = -distance(it.end(), upper_bound(it.begin(), it.end(), -x)) - 1,
        tf = distance(t.begin(), upper_bound(t.begin(), t.end(), x));
    if(sb >= 0) m = min(m, x - s[sb] + st[sb]);
    if(sf < a) m = min(m, s[sf] - x + st[sf]);
    if(tb >= 0) m = min(m, x - t[tb] + ts[tb]);
    if(tf < b) m = min(m, t[tf] - x + ts[tf]);
    o[i] = m;
  }
  for(int i = 0; i < q; i++) printf("%lld\n", o[i]);
}