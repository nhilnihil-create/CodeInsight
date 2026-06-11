#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <array>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <functional>
#include <random>

using namespace std;
using lli = long long int;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0)
{ v = vector<T>(n+o); for (lli i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (lli i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

lli n, m;
vector<lli> e[100001];

lli color[100001];
bool isBipartite(lli v, lli c) {
  color[v] = c;
  for (lli u : e[v]) {
    if (color[u] == 0) {
      bool r = isBipartite(u, -c);
      if (!r) return r;
    } else if (color[u] == c) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> n >> m;
  for (lli i=0; i<m; ++i) {
    lli a, b; cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  bool bip = isBipartite(1, 1);

  if (bip) {
    lli w=0, b=0;
    for (lli i=1; i<=n; ++i) {
      if (color[i]==1) w++;
      else b++;
    }
    cout << w*b - m << '\n';
  } else {
    cout << n*(n-1)/2 - m << '\n';
  }
  return 0;
}
