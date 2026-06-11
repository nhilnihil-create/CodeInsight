#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

const int N = 100010;
ii b[N];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  int u, v;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    b[i] = ii(u, v);
  }
  sort(b, b + m, [&](ii a, ii b) {
    return ii(a.second, a.first) < ii(b.second, b.first);
  });

  int last = b[0].second - 1, ans = 1;
  for (int i = 1; i < m; i++) {
    if (b[i].first <= last) continue;
    else { last = b[i].second - 1; ans++; }
  }
  printf("%d\n", ans);
}

