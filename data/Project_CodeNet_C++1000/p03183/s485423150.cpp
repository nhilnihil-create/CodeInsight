#include<iostream>
#include<cstdint>
#include<algorithm>

struct block {
  int w, s;
  int64_t v;
};

bool operator< (block const& l, block const& r) {
  return l.w+l.s < r.w+r.s;
}

int const MAXN = 1000;
int const MAXW = 10000;
int const MAXS = 10000;

int64_t dp[MAXN][MAXW+MAXS+1];
int64_t const INF = (int64_t)1<<59;

block blks[MAXN];
int N;

int main() {
  std::cin >> N;
  for(int i = 0; i < N; ++i) {
    std::cin >> blks[i].w >> blks[i].s >> blks[i].v;
  }
  std::sort(blks, blks+N);
  int maxws = blks[N-1].w + blks[N-1].s;

  for(int s = 0; s <= MAXW; ++s) dp[0][s] = -INF;
  dp[0][0] = 0;
  dp[0][blks[0].w] = blks[0].v;
  for(int n = 1; n < N; ++n) {
    for(int s = 0; s < blks[n].w; ++s) dp[n][s] = dp[n-1][s];
    int ub = blks[n].w+blks[n].s;
    for(int s = blks[n].w; s <= ub; ++s) {
      dp[n][s] = std::max(dp[n-1][s], dp[n-1][s-blks[n].w] + blks[n].v);
    }
    for(int s = ub+1; s <= maxws; ++s) dp[n][s] = dp[n-1][s];
  }
  int64_t m = 0;
  for(int s = 0; s <= maxws; ++s) m = std::max(m, dp[N-1][s]);
  std::cout << m << std::endl;
  return 0;
}
