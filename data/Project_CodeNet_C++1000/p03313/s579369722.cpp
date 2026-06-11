#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

using namespace std;

const int N = 1 << 18;

int a[N];
int f[N];
int g[N][2];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (1 << n); ++i) {
    scanf("%d", a + i);
  }
  g[0][0] = 0;
  g[0][1] = 0;
  f[0] = 0;
  for (int i = 1; i < (1 << n); ++i) {
    set<int> s;
    s.insert(i);
    for (int j = 0; j < n; ++j) {
      if (i >> j & 1) {
        s.insert(g[i ^ 1 << j][0]);
        s.insert(g[i ^ 1 << j][1]);
      }
    }
    vector<pair<int, int>> w;
    for (int e : s) {
      w.emplace_back(a[e], e);
    }
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    g[i][0] = w[0].second;
    g[i][1] = w[1].second;
    f[i] = max(f[i - 1], w[0].first + w[1].first);
    printf("%d\n", f[i]);
  }
}
