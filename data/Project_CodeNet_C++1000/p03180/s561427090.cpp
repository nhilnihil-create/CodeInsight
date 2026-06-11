#include<iostream>
#include<cstdint>
#include<algorithm>

int const MAXN = 16;

int N;
int64_t a[MAXN][MAXN];

int64_t dp[1<<MAXN];
int64_t tb[1<<MAXN];

void init() {
  for(int i = 0; i < (1<<N); ++i) tb[i] = 0;
  for(int i = 0; i < N; ++i) for(int j = i+1; j < N; ++j) {
    int x = (1<<i) + (1<<j);
    for(int k = 0; k < (1<<N); ++k) if((x&k)==x) tb[k] += a[i][j];
  }
}

int64_t calc(int bits) {
  if(dp[bits] >= 0) return dp[bits];
  int64_t ret = tb[bits];
  int i = bits-1;
  while(i > 0) {
    int j = bits - i;
    if(i < j) ret = std::max(ret, calc(i)+calc(j));
    --i;
    i&=bits;
  }
  return dp[bits] = ret;
}

int main() {
  std::cin >> N;
  for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) std::cin >> a[i][j];
  for(int i = 0; i < (1<<N); ++i) dp[i] = -1;
  init();
  std::cout << calc((1<<N)-1) << std::endl;
  return 0;
}
