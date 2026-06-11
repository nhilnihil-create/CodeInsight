#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <cassert>
 
using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  ll l = 2, r = 2;
  for (int i = n - 1; i >= 0; --i) {
    ll x = r - (r % a[i]);
    if (x < l) {
      cout << "-1\n";
      return 0;
    }
    ll mx = r - (r % a[i]);
    ll mn = l + ((a[i] - (l % a[i])) % a[i]);
    l = mn;
    r = mx + a[i] - 1;
  }
  cout << l << ' ' << r << '\n';
} 
