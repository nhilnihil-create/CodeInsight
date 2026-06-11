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
  int A, B, C; cin >> A >> B >> C;
  int v = max({A, B, C});
  int count = 3 * v - (A + B + C);
  if (count % 2 == 0) cout << count/2 << endl;
  else                cout << (count/2) + 2 << endl;
}
