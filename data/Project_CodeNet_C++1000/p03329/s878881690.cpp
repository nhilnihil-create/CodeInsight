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
  int N; cin >> N;

  int vmin = 1e9;
  for (int c6 = 0; c6 <= N/6; c6++) {
    for (int c9 = 0; c9 <= N/9; c9++) {
      int x = N - c6 * 6 - c9 * 9;
      if (x < 0) continue;

      int a = c6;
      int y = 0;
      while (a > 0) {
        y += a % 6;
        a /= 6;
      }

      int b = c9;
      int z = 0;
      while (b > 0) {
        z += b % 9;
        b /= 9;
      }

      vmin = min(vmin, x + y + z);
    }
  }
  cout << vmin << endl;
}
