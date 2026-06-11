#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int l[5 + nmax], r[5 + nmax];
ll sum[5 + nmax], sum2[5 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> l[i] >> r[i];
  std::sort(l + 1, l + n + 1);
  std::sort(r + 1, r + n + 1);
  std::reverse(l + 1, l + n + 1);
  for(int i = 1;i <= n; i++)
    sum[i] = sum[i - 1] + l[i];
  for(int i = 1; i <= n; i++)
    sum2[i] = sum2[i - 1] + r[i];
  ll result = 0;
  for(int i = 1;i <= n; i++) {
    result = std::max(result, sum[i - 1] - sum2[i]);
    result = std::max(result, sum[i] - sum2[i]);
    result = std::max(result, sum[i] - sum2[i - 1]);
  }
  std::cout << 2 * result;
  return 0;
}
