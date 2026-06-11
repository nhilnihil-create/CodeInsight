#include <bits/stdc++.h>
#define eps 1e-3
#define pi acos(-1.0)
#define inf 0x3f
#define INF 0x3f3f3f3f
#define pb push_back
#define debug1 cout<<"&&";
#define debug2 cout<<"**";
#define ms(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
typedef pair<long long, long long> pll;
const int mod = 1e9 + 7;
const int N = 3e2+10;
const int M = 1e6+10;
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline ll Pow(ll a, ll b) { ll ans = 1; for( ; b; b >>= 1) { if(b&1) ans = ans * a % mod; a = a * a % mod;} return ans;}
inline ll Mul ( ll a, ll b)  { ll lf = a * ( b >> 25ll ) % mod * ( 1LL << 25 ) % mod; ll rg = a * ( b & ( ( 1ll << 25 ) - 1 ) ) % mod; return ( lf + rg ) % mod;}
inline ll C(ll y, ll x) { ll ans = 1; if(y < 0 || x < 0 || y < x) return 0; y %= mod; if(!y || !x) return 1; rep(i, 0, x-1) ans = ans * (y-i) % mod; rep(i, 1, x) ans = ans * Pow(i, mod-2) % mod; return ans; }
//==================================================================================================================================================================//

int n, c[5];
db ans, dp[N][N][N];

int main() {
   scanf("%d", &n);
   rep(i, 1, n) {
      int x; scanf("%d", &x);
      c[x]++;
   }
   rep(k, 0, n) rep(j, 0, n) rep(i, 0, n) {
      if(i || j || k) {
         if(i) dp[i][j][k] += dp[i-1][j][k] * i / (i+j+k);
         if(j) dp[i][j][k] += dp[i+1][j-1][k] * j / (i+j+k);
         if(k) dp[i][j][k] += dp[i][j+1][k-1] * k / (i+j+k);
         dp[i][j][k] += (db)n / (i+j+k);
      }
   }
   ans = dp[c[1]][c[2]][c[3]];
   printf("%.9lf\n", ans);
   return 0;
}