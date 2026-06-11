// KALAM
# include<bits/stdc++.h>

using namespace std;

const int N = 5000 + 77;
int n , X , Y;
int a[N] , b[N] , F[N];
long long dp[N][N];
int main() {
   memset(dp , 63 , sizeof(dp));
   for(int i = 0;i < N;++ i)
      dp[0][i] = 0;
   scanf("%d" , & n);
   scanf("%d %d" , & X , & Y);
   for(int i = 1;i <= n;++ i)
      scanf("%d" , a + i);
   for(int i = 1;i <= n;++ i) {
      for(int j = i;j <= n;++ j)
         dp[i][j] = 0;
      for(int j = 1;j < i;++ j)
         F[i] += (a[j] > a[i]);
      b[i] = i;
      for(int j = i;j > 1;-- j)
         if(a[b[j]] < a[b[j - 1]])
            swap(b[j] , b[j - 1]);
      for(int j = 2;j <= i;++ j) {
         int t = i - j + 1;
         int pos = b[i - t + 1];
         int leftmore = F[pos];
         int rightmore = t - 1 - F[pos];
         int rightless = i - pos - rightmore;
         dp[i][t] = dp[pos - 1][leftmore + 1] + rightless * 1ll * Y;
         if(rightless == 0)
            dp[i][t] = min(dp[i][t] , dp[i][t + 1]);
         else
            dp[i][t] = min(dp[i][t] , dp[i][t + 1] + X);
      }
   }

   printf("%lld\n" , dp[n][1]);
   return 0;
}
