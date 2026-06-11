#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

const int N = 100'009;

long long a[N];
int o[N];
int cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  map<long long, int> w;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a + i);
    w[a[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    o[i] = i;
  }
  sort(o, o + n, [](int i, int j) {
    return a[i] > a[j];
  });
  for (int i = 0; i < n; ++i) {
    cnt[i] = 1;
  }
  vector<pair<int, int>> ans;
  long long sum = 0;
  for (int i = 0; i < n - 1; ++i) {
    int x = o[i];
    long long v = a[x] - (n - (cnt[x] + 1)) + (cnt[x] - 1);
    if (v >= a[x] || w.count(v) == 0) {
      puts("-1");
      return 0;
    }
    sum += cnt[x];
    int y = w[v];
    ans.emplace_back(x, y);
    cnt[y] += cnt[x];
  }
  if (a[o[n - 1]] != sum) {
    puts("-1");
    return 0;
  }
  for (auto &e : ans) {
    printf("%d %d\n", e.first + 1, e.second + 1);
  }
}
