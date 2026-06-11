// Author: 23forever
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
typedef long long LL;
const int MAXN = 20;
const int MAXM = 60;
const int INF = 0x3f3f3f3f;
using namespace std;

inline void enableFileIO() {
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
}

inline int read() {
  int x = 0, w = 1;
  char c = ' ';

  while (c < '0' || c > '9') {
    c = getchar();
    if (c == '-') w = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }

  return x * w;
}

struct Edge {
  int u, v, w;
  Edge() {}
  Edge(int _u,int _v, int _w) : u(_u), v(_v), w(_w) {}
}e[MAXM + 5];

int tot;
inline void add(int u, int v, int w) {
  e[++tot] = Edge(u, v, w);
}

int n, l;

void init() {
  //enableFileIO();
  l = read();
}

inline int lowbit(int x) {
  return x & (-x);
}

int main() {
  init();
  
  n = 20;
  for (int i = n - 1; i > 1; --i) {
    add(i, i + 1, 0);
    add(i, i + 1, 1 << (20 - i - 1));
  }
  while (l) {
    int p = log2(lowbit(l));
    if (p == 19) {
      add(1, 2, 0);
      add(1, 2, 1 << 18);
    } else {
      add(1, 20 - p, l ^ lowbit(l));
    }
    l ^= lowbit(l);
  }

  printf("%d %d\n", n, tot);
  for (int i = 1; i <= tot; ++i) {
    printf("%d %d %d\n", e[i].u, e[i].v, e[i].w);
  }

  return 0;
}
