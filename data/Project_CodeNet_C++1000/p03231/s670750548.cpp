#include <cmath>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int md = 1;
  for (int i = n; i >= 1; i--) {
    if (n % i == 0 && m % i == 0) {
      md = i;
      break;
    }
  }
  ll ans = n * (ll) m / md;
  map <ll, set <char> > q;
  for (int it = 0; it < n; it++) {
    ll cur = it * (ll) (ans / n);
    q[cur].insert(s[it]);
  }
  for (int it = 0; it < m; it++) {
    ll cur = it * (ll) (ans / m);
    q[cur].insert(t[it]);
  }
  for (auto c : q) {
    if (c.second.size() > 1) {
      cout << "-1\n";
      return 0;
    }
  }
  cout << ans << endl;
}
