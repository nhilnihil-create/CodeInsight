#include <cstdio>

const int MaxN = 3000 + 5;
const int Mod = 1000000007;

int N;
char S[MaxN];
int F[MaxN], G[MaxN];

inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline int sub(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }

void init() {
  scanf("%d", &N);
  scanf("%s", S + 1);
}

inline void makePre() {
  G[0] = 0;
  for (int i = 1; i <= N; ++i)
    G[i] = add(G[i - 1], F[i]);
}

void solve() {
  F[1] = 1;
  makePre();
  for (int i = 2; i <= N; ++i) {
    for (int j = 1; j <= i; ++j) {
      if (S[i - 1] == '<') F[j] = G[j - 1];
      else F[j] = sub(G[N], G[j - 1]);
    }
    makePre();
  }
  printf("%d\n", G[N]);
}

int main() {
  init();
  solve();
  return 0;
}