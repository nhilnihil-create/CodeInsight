#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int N;

LL dfs(LL x, bool b3, bool b5, bool b7) {
  if (x > N) return 0;
  LL cnt = (b3 && b5 && b7) ? 1 : 0;

  x *= 10;
  cnt += dfs(x + 3, true, b5, b7);
  cnt += dfs(x + 5, b3, true, b7);
  cnt += dfs(x + 7, b3, b5, true);
  return cnt;
}

int main() {
  cin >> N;
  LL cnt = dfs(3, true, false, false);
  cnt += dfs(5, false, true, false);
  cnt += dfs(7, false, false, true);
  cout << cnt <<endl;
}
