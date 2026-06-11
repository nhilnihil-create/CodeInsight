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

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  int best = 1e9;
  auto get = [&] (int x) {
    int ret = 0;
    while (x > 0) {
      ret += x % 10;
      x /= 10;
    }
    return ret;
  };
  for (int a = 1; a < n; ++a) {
    int b = n - a;
    best = min(best, get(a) + get(b)); 
  }
  cout << best << '\n';
}

