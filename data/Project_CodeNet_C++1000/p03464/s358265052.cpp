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
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;

int main(void) {

  int k;
  cin >> k;
  
  vector<ll> a(k);
  rep(i, k) cin >> a[i];
  if (a[k - 1] != 2) {
    cout << -1 << endl;
    return 0;
  }

  pair< ll, ll > sec[100010];
  sec[k - 1].first = 2; sec[k - 1].second = 3;
  for (int i = k - 2; i >= 0; i--) {
    ll l = sec[i + 1].first, r = sec[i + 1].second;
    l = ((l - 1LL) / a[i] + 1LL) * a[i];
    r = (r / a[i] + 1LL) * a[i] - 1;
    //cout << l << " " << r << endl;
    if (!(l <= r)) {
      cout << -1 << endl;
      return 0;
    }
    sec[i].first = l; sec[i].second = r;
  }
  cout << sec[0].first << " " << sec[0].second << endl;

  return 0;
  
}
