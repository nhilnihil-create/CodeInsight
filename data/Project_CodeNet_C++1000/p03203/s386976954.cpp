#ifdef DBG1
  #define LOCAL
#endif

#ifdef LOCAL
  #define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#ifdef DBG1
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

bool solve() {
  int n;
  int W, H;
  if (scanf("%d%d%d", &H, &W, &n) != 3) { return false; }

  vector<int> minY(H + 1, W);
  minY[H] = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    minY[x] = min(minY[x], y);
  }

  int res = 0;
  int x = 0, maxY = 0;
  while (1) {
    if (minY[x + 1] <= maxY) {
      break;
    }
    x++;
    res += 1;
    maxY = min(maxY + 1, minY[x] - 1);
  }
  printf("%d\n", res + 1);


  return true;
}

int main() {
  while (solve());
  return 0;
}