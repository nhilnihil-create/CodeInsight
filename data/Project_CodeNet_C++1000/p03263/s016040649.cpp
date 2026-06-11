#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

const int N = 550;
int a[N][N], n, m;

void solve() {
  vector<ii> p;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      for (int j = m - 1; j >= 0; j--) p.push_back({i, j});
    } else {
      for (int j = 0; j < m; j++) p.push_back({i, j});
    }
  }
  vector<ii> fr, to;
  for (int i = 0; i < sz(p) - 1; i++) {
    int t = a[p[i].first][p[i].second];
    if (t & 1) {
      fr.push_back(p[i]);
      to.push_back(p[i + 1]);
      a[p[i + 1].first][p[i + 1].second]++;
    }
  }
  printf("%d\n", sz(fr));
  for (int i = 0; i < sz(fr); i++) {
    printf("%d %d %d %d\n", fr[i].first + 1, fr[i].second + 1, to[i].first + 1, to[i].second + 1);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &a[i][j]);
  solve();
}

