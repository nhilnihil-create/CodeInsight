#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <complex>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007LL;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;

ll powMod(ll x, ll n, ll mod) {
  if (n == 0) return 1LL;
  ll t = powMod(x, n/2, mod);
  t = t * t % mod;
  if (n & 1) return t * x % mod;
  return t;
}

ll a[(1 << 18) + 10];

int main(void) {

  int n, D;
  
  scanf("%d", &D);
  n = 1 << D;
  
  rep(i, n) scanf("%lld", &a[i]);

  

  vector<ll> ans(n + 10);
  vector< pair<ll, ll> > b(n + 10);
  vector<int> c(D + 10);
  

  b[0].first = 0;
  b[0].second = -1;
  b[1].first = 1;
  b[1].second = -1;

  
  ans[1] = a[0] + a[1];
  printf("%lld\n", ans[1]);

  
  for (int k = 2; k < n; k++) {
    c.clear();
    int j = 0;
    for (int i = 0; i <= D; i++) {
      if ((k >> i) & 1) c[j++] = i;
    }
    
    vector<ll> d;
    for (int i = j - 2; i >= 0; i--) {
      d.push_back(b[k - (1 << c[i])].first);
      if (b[k - (1 << c[i])].second != -1) {
	d.push_back(b[k - (1 << c[i])].second);
      }
    }
    d.push_back(k);
      
    int f = d[0], s = -1;

    for (int i = 0; i < d.size(); i++) {
      if (a[f] < a[d[i]]) f = d[i];
    }

    for (int i = 0; i < d.size(); i++) {
      if (d[i] != f && (s == -1 || a[s] < a[d[i]])) s = d[i];
    }
    
    b[k].first = f;
    b[k].second = s;

    int l = k, m = j - 1;
    ll g = 0;
    while (m >= 0) {
      l -= 1 << c[m--];
      g = max(g, a[b[l].first]);
    }

    if (s == -1) ans[k] = a[f] + g;
    else ans[k] = a[f] + max(g, a[s]);
    ans[k] = max(ans[k - 1], ans[k]);

    printf("%lld\n", ans[k]);

  }

  return 0;

}

    
