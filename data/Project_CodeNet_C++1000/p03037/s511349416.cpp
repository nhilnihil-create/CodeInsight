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

int main() {
  int N, M; cin >> N >> M;
  int vmin = 0, vmax = N + 1;
  for (int i = 0; i < M; ++i) {
    int L, R; cin >> L >> R;
    vmin = max(vmin, L);
    vmax = min(vmax, R);
  }
  cout << max(0, vmax - vmin + 1) << endl;
}
