#include <stdio.h>
#include <algorithm>
#define SIZE 3005

  const int mod = (int)1e9 + 7;
  int dp[SIZE][SIZE];
  char str[SIZE];

  inline int add(int a, int b, int mod) {a += b; return a >= mod ? a - mod : a;}
  inline int sub(int a, int b, int mod) {a -= b; return a < 0 ? a + mod : a;}

  int main(void) {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n-1; i++) scanf(" %c",&str[i]);

        dp[1][1] = 1;
        for(int len=2; len<=n; len++) {
                for(int i=1; i<=len-1; i++) dp[len-1][i] = add(dp[len-1][i-1], dp[len-1][i], mod);

                for(int b=1; b<=len; b++) {
                        int l=1, r=b-1;
                        if(str[len-2] == '>') l = b, r = len - 1;
                        if(l > r) continue;

                        dp[len][b] = add(dp[len][b], sub(dp[len-1][r], dp[len-1][l-1], mod), mod);
                }
        }

        int ans=0;
        for(int i=1; i<=n; i++) ans = add(ans, dp[n][i], mod);

        printf("%d", ans);
        return 0;
  }


