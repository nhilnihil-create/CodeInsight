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
  auto gcd = [&] (ll a, ll b) {
    while (b) {
      ll cur = a % b;
      a = b;
      b = cur;
    }
    return a;
  };
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b > a) {
      cout << "No\n";
      continue;
    }
    if (b > d) {
      cout << "No\n";
      continue;
    }
    ll x = c - b + 1;
    ll cur = gcd(b, d);
    ll ost = x % cur;
    if (ost < 0) ost += cur;
    ost = ost - a % cur;
    if (ost < 0) ost += cur;
    if (ost) x += cur - ost;
    cout << (x >= 0 ? "Yes\n" : "No\n");
  }
}
