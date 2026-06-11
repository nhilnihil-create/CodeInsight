#define _USE_MATH_DEFINES
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;

const int N = 2e5 + 10;
set<int> a[N];

int main() {
  int n, m, len;
  scanf("%d%d%d", &n, &m, &len);
  set<ii> forbid;
  while (len--) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x; --y;
    forbid.insert({x, y});
    a[y].insert(x);
  }
  int ret = INF;
  int x = 0, y = 0;
  while (true) {
    auto it = a[y].upper_bound(x);
    int nxt = (it == a[y].end() ? n : *it);
    ret = min(ret, nxt);
    // trace(x, y, ret);
    for (++x; x != nxt; ++x) {
      if (!forbid.count({x, y + 1})) {
        y += 1;
        break;
      }
    }
    if (x == nxt) break;
  }
  printf("%d\n", ret);
  return 0;
}
