#include <cstdio>
#include <set>

int main() {
  int n;
  scanf("%d", &n);

  std::multiset<int> d;
  for (int i = 0; i < n; ++i) {
    int di;
    scanf("%d", &di);
    d.insert(di);
  }

  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int t;
    scanf("%d", &t);
    auto it = d.find(t);
    if (it == d.end()) return puts("NO"), 0;
    d.erase(it);
  }

  puts("YES");
}
