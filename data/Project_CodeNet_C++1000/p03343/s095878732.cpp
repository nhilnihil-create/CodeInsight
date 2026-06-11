#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2'009;

int a[N];
int b[N];

int main() {
  int n, k, q;
  scanf("%d %d %d", &n, &k, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    b[i] = a[i];
  }
  a[n] = 0;
  sort(b, b + n);
  int ans = 2'000'000'000;
  for (int s = 0; s < n; ++s) {
    vector<int> cur, all;
    for (int i = 0; i <= n; ++i) {
      if (a[i] < b[s]) {
        sort(cur.begin(), cur.end());
        for (int j = 0; j < (int)cur.size() - k + 1; ++j) {
          all.push_back(cur[j]);
        }
        cur.clear();
      } else {
        cur.push_back(a[i]);
      }
    }
    sort(all.begin(), all.end());
    if ((int)all.size() >= q) {
      ans = min(ans, all[q - 1] - all[0]);
    }
  }
  printf("%d\n", ans);
}
