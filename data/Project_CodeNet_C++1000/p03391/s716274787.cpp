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
  LL sum = 0;
  LL v = 1e18;
  bool same = true;
  for (int i = 0; i < N; ++i) {
    LL A, B; cin >> A >> B;
    sum += A;
    if (A != B) same = false;
    if (A > B) v = min(v, B);
  }
  if (same) cout << 0 << endl;
  else cout << sum - v << endl;
}
