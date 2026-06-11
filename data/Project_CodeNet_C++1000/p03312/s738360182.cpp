#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int N = 200'009;

int a[N];
vector<pair<long long, long long>> f[2][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int ro = 0; ro < 2; ++ro) {
    for (int i = 0; i < n; ++i) {
      f[ro][i].clear();
    }
    long long sum = a[0], pref = 0;
    for (int i = 1, j = 0; i < n; ++i) {
      sum += a[i];
      while (pref + a[j] <= sum - pref - a[j]) {
        pref += a[j];
        ++j;
      }
      if (j > 0) {
        f[ro][i].emplace_back(pref, sum - pref);
      }
      if (j < i) {
        f[ro][i].emplace_back(sum - pref - a[j], pref + a[j]);
      }
    }
    reverse(a, a + n);
  }
  long long ans = 1'000'000'000'000'000'000;
  for (int i = 1; i < n - 2; ++i) {
    for (auto &e1 : f[0][i]) {
      for (auto &e2 : f[1][n - (i + 1) - 1]) {
        ans = min(ans, max(e1.second, e2.second) - min(e1.first, e2.first));
      }
    }
  }
  printf("%lld\n", ans);
}
