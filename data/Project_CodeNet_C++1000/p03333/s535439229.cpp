#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

void precalc() {
}

const int maxn = (int) 1e5 + 5;
int n;
int ls[maxn], rs[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &ls[i], &rs[i]);
  }
  return true;
}

set<pair<int, int> > st[2];

long long solve1() {
  int x = 0;
  st[0].clear();
  st[1].clear();
  for (int i = 0; i < n; i++) {
    st[0].insert(make_pair(rs[i], i));
    st[1].insert(make_pair(-ls[i], i));
  }
  int t = 0;
  long long res = 0;
  while (!st[0].empty()) {
    int id = st[t].begin()->second;
    st[0].erase(make_pair(rs[id], id));
    st[1].erase(make_pair(-ls[id], id));
    if (x < ls[id]) {
      res += ls[id] - x;
      x = ls[id];
    } else if (x > rs[id]) {
      res += x - rs[id];
      x = rs[id];
    }
    t ^= 1;
  }
  res += abs(x);
  x = 0;
  return res;
}

void solve() {
  long long res = 0;
  for (int it = 0; it < 2; it++) {
    res = max(res, solve1());
    for (int i = 0; i < n; i++) {
      ls[i] *= -1;
      rs[i] *= -1;
      swap(ls[i], rs[i]);
    }
  }
  printf("%lld\n", res);
}

int main() {
  while (read()) {
    solve();
  }
  return 0;
}