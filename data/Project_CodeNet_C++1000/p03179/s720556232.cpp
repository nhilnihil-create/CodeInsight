#include <bits/stdc++.h>
#define eps 1e-3
#define pi acos(-1.0)
#define inf 0x3f
#define INF 0x3f3f3f3f
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
const int N = 3e3+10;
const int M = 1e6+10;
/*=================================================================================*/

ll dp[N][N], n, ans;
char chr[N];

int main() {
   cin>>n;
   scanf("%s", chr+1);
   dp[1][1] = 1;
   for(int i = 2; i <= n; ++i) {
      if(chr[i-1] == '<') {
         dp[i][1] = 0;
         for(int j = 2; j <= i; ++j) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) % mod;
         }
      } else {
         dp[i][i] = 0;
         for(int j = i-1; j; --j) {
               dp[i][j] = (dp[i][j+1] + dp[i-1][j]) % mod;
         }
      }
   }
   for1(i, n) {
      ans = (ans + dp[n][i]) % mod;
   }
   cout<<ans<<endl;
}

/*
 4 5 6 7 3 2 1
*/