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

LL N;
int dfs(LL n, bool b3, bool b5, bool b7) {
  if (n > N) return 0;

  int cnt = 0;
  if (b3 && b5 && b7) ++cnt;
  cnt += dfs(n * 10 + 3, true, b5, b7);
  cnt += dfs(n * 10 + 5, b3, true, b7);
  cnt += dfs(n * 10 + 7, b3, b5, true);

  return cnt;
}

int main() {
  cin >> N;
  int cnt = 0;
  cnt += dfs(3, true, false, false);
  cnt += dfs(5, false, true, false);
  cnt += dfs(7, false, false, true);
  cout << cnt << endl;
}
