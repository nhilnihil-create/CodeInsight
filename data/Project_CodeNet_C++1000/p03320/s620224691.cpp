#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int dsum(lint v) {
  int result = 0;
  while (v > 0) {
    result += v % 10;
    v /= 10;
  }
  return result;
}

int ndigit(int v) {
  int result = 0;
  while (v) {
    result += 1;
    v /= 10;
  }
  return result;
}

int main() {
  const lint limit = 1000000000000000LL;
  vector<lint> result;
  for (int v = 1; v <= 9; ++v) result.push_back(v);
  for (int v = 1; v < 1000; ++v) {
    int nd = ndigit(v);
    lint value = v;
    if (v != 9 && v % 10 == 9) continue;
    for (int n9 = 0; n9 <= 15 + 1; ++n9) {
      if (value > limit)
        break;
      if (n9 >= nd)
        result.push_back(value);
      value = 10LL * value + 9;
    }
  }
  sort(result.begin(), result.end());
  result.resize(unique(result.begin(), result.end()) - result.begin());

  vector<lint> result2;
  lint smallest = -1;
  for (int i = (int)result.size() - 1; i >= 0; --i) {
    if (smallest == -1 ||
        result[i] * dsum(smallest) < smallest * dsum(result[i])) {
      smallest = result[i];
    }
    if (result[i] * dsum(smallest) <= smallest * dsum(result[i]))
      result2.push_back(result[i]);
  }
  reverse(result2.begin(), result2.end());

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n && i < (int)result2.size(); ++i)
    printf("%lld\n", result2[i]);
  return 0;
}
