#include <bits/stdc++.h>
#define eps 1e-3
#define pi acos(-1.0)
#define inf 0x3f
#define INF 0x3f3f3f3f3f3f3f3f
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
const int N = 21;
const int M = 3e6 + 10;
/*=================================================================================*/

int n, mp[N][N];
ll dp[M];

int main() {
   cin>>n;
   for0(i, n) for0(j, n) {
      scanf("%d", &mp[i][j]);
   }
   dp[0] = 1;
   for0(i, (1<<n)) {
      int cnt = 0;
      for0(j, n) {
         if((i >> j) & 1) {
            cnt++; // 记录已经匹配完成的人数
         }
      }
      cnt--;
      for0(j, n) {
         if(mp[cnt][j] && (i & (1<<j))) {
            dp[i] = (dp[(1<<j)^i] + dp[i]) % mod;
            // debug1 printf("%d %d %d %d\n", i, j, mp[cnt][j], cnt);
         }
      }
   }
   cout<<dp[(1<<n)-1]<<endl;
}