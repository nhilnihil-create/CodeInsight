#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2000 * 2000;

using bs = bitset <N>;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  bs bp;
  bp[0] = 1;
  for (int i = 0; i < n; ++i) {
    bp |= (bp << a[i]);
  }
  for (int i = 0; i < N; ++i) {
    if (bp[i] && 2 * i >= sum) {
      cout << i << '\n';
      return 0;
    }
  }
}

