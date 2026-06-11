#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 1000 + 5;
const int MaxW = 20000 + 5;

int N;
int W[MaxN], S[MaxN], V[MaxN];
long long Dp[MaxW];

template <typename Typ>
inline Typ max(Typ x, Typ y) { return x > y ? x : y; }

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i)
    scanf("%d %d %d", &W[i], &S[i], &V[i]);
}

void solve() {
  static int lnk[MaxN];
  for (int i = 1; i <= N; ++i) lnk[i] = i;
  std::sort(lnk + 1, lnk + 1 + N, [](int x, int y){ return W[x] + S[x] < W[y] + S[y]; });
  for (int I = 1; I <= N; ++I) {
    int i = lnk[I];
    for (int j = S[i] + W[i]; j >= W[i]; --j)
      Dp[j] = max(Dp[j], Dp[j - W[i]] + V[i]);
  }
  long long ans = 0;
  for (int i = 1; i <= 20000; ++i) ans = max(ans, Dp[i]);
  printf("%lld\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}