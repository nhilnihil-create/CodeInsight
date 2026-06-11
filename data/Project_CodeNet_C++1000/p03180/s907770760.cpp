#include <cstdio>
#include <algorithm>

int n;
int A[16][16];

long long int dp[1<<16];
long long int dp2[2][1<<16];

void conv(long long int *r, const long long int *a){
  for(int x = 0; x < (1 << n); x++) r[x] = 0;
  for(int x = 0; x < (1 << n); x++){
    int z = ~x & ((1 << n) - 1);
    for(int y = z; y; y = (y-1) & z){
      r[x^y] = std::max(r[x^y], a[x] + a[y]);
    }
  }
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &A[i][j]);
    }
  }
  for(int x = 0; x < (1<<n); x++){
    dp[x] = dp[x&(x-1)];
    int i = __builtin_ctz(x);
    for(int y = x&(x-1); y; y &= y-1){
      int j = __builtin_ctz(y);
      dp[x] += A[i][j];
    }
    dp2[0][x] = dp[x];
  }

  for(int i = 0; i < 4; i++){
    bool b = i&1;
    conv(dp2[!b], dp2[b]);
  }
  long long int ans = dp2[0][(1<<n)-1];
  printf("%lld\n", ans);
  return 0;
}
