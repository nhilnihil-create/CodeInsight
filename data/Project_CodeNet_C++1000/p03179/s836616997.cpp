#include <cstdio>

using u32 = unsigned int;

int n;
bool S[2999];
u32 dp[3001];

constexpr u32 mod = 1000000007;

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n-1; i++){
    char c;
    do { scanf("%c", &c); } while(c != '>' && c != '<');
    S[i] = c == '>';
  }

  for(int j = 0; j < n; j++) dp[j] = 1;

  for(int i = 0; i < n-1; i++){
    if(S[i]){
      for(int j = 0; j < n - i; j++){
        dp[j] = dp[j+1];
      }
      for(int j = n-i-3; j >= 0; j--){
        dp[j] += dp[j+1];
        if(dp[j] >= mod) dp[j] -= mod;
      }
    }
    else {
      for(int j = 0; j < n - i - 1; j++){
        dp[j] += dp[j-1];
        if(dp[j] >= mod) dp[j] -= mod;
      }
    }
//    for(int j = 0; j < n - i; j++) printf("%d ", dp[j]);
//    puts("");
  }

  printf("%d\n", dp[0]);

  return 0;
}
