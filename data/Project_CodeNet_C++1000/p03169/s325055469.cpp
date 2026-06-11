#include <bits/stdc++.h>
#define eps 1e-3
#define pi acos(-1.0)
#define inf 0x3f
#define INF 1e18
#define pb push_back
#define debug1 cout<<"&&";
#define debug2 cout<<"**";
#define ms(a, x) memset(a, x, sizeof(a))
#define for0(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
typedef pair<long long, long long> pll;
const int mod = 1e9 + 7;
const int N = 310;
const int M = 1e6+10;
/*=================================================================================*/

int cnt[10], a, n;
db dp[N][N][N];

db dfs(int a, int b, int c) {
   if(!a && !b && !c) return 0;
   if(dp[a][b][c]) return dp[a][b][c];
   db sum = a+b+c;
   db ans = 1.0*n / sum;
   if(a) ans += 1.0*a/sum * dfs(a-1, b, c);
   if(b) ans += 1.0*b/sum * dfs(a+1, b-1, c);
   if(c) ans += 1.0*c/sum * dfs(a, b+1, c-1);
   dp[a][b][c] = ans;
   return ans;
}

int main() {
   cin>>n;
   for1(i, n) {
      scanf("%d", &a);
      cnt[a]++;
   }
   db ans = dfs(cnt[1], cnt[2], cnt[3]);
   printf("%.8lf\n", ans);
   return 0;
}