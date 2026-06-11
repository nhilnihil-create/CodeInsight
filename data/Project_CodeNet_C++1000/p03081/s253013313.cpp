#include <bits/stdc++.h>

using namespace std;

const int N = 200200;

char s[N], t[N], d[N];

int main() {
  int n, m;
  scanf("%d %d %s", &n, &m, s + 1);
  for (int i = 1; i <= m; ++i) {
    scanf(" %c %c", &t[i], &d[i]);
  }
  auto gol = [&](int md) {
    int nw = md;
    for (int i = 1; i <= m; ++i) {
      if (nw == 0) return true;
      if (nw == n + 1) return false;
      if (s[nw] == t[i]) {
        if (d[i] == 'L') nw--;
        else nw++;
      }
    }
    return nw == 0;
  };
  int tl, tr;
  {
    int l = 0, r = n + 1;
    while (l < r) {
      int md = (l + r + 1) >> 1;
      if (gol(md)) l = md;
      else r = md - 1;
    }
    tl = l;
  }
  auto gor = [&](int md) {
    int nw = md;
    for (int i = 1; i <= m; ++i) {
      if (nw == 0) return false;
      if (nw == n + 1) return true;
      if (s[nw] == t[i]) {
        if (d[i] == 'L') nw--;
        else nw++;
      }
    }
    return nw == n + 1;
  };
  {
    int l = 0, r = n + 1;
    while (l < r) {
      int md = (l + r) >> 1;
      if (gor(md)) r = md;
      else l = md + 1;
    }
    tr = r;
  }
  printf("%d\n", tr - tl - 1);
}
