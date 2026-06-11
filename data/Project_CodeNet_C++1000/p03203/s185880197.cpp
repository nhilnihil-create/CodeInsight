#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 200010;

int n, m;
set<int> obs[N];

int main() {
	ios::sync_with_stdio(false);
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
#endif

  int k;
  scanf("%d%d%d", &n, &m, &k);
  while (k--) {
    int x, y;
    scanf("%d%d", &x, &y);
    obs[y].insert(x);
  }
  for (int i = 1; i <= m; ++i) {
    obs[i].insert(n + 1);
  }
  int ans = *obs[1].begin(), cur = 1;
  for (int i = 2; i <= m; ++i) {
    ++cur;
    while (obs[i].count(cur) && cur <= ans)
      ++cur;
    if (cur > ans)
      break;
    ans = min(ans, *obs[i].lower_bound(cur));
  }
  printf("%d\n", ans - 1);

  return 0;
}

