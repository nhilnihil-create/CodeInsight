#include <bits/stdc++.h>
#define eps 1e-7
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
mt19937_64 mrand(random_device{}()); 
const int mod = 1e9 + 7;
const int N = 110;
const int M = 1e5 + 10;
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline ll Pow(ll a, ll b) { ll ans = 1; for( ; b; b >>= 1) { if(b&1) ans = ans * a % mod; a = a * a % mod;} return ans;}
inline ll Mul ( ll a, ll b)  { ll lf = a * ( b >> 25ll ) % mod * ( 1LL << 25 ) % mod; ll rg = a * ( b & ( ( 1ll << 25 ) - 1 ) ) % mod; return ( lf + rg ) % mod;}
inline ll C(ll y, ll x) { ll ans = 1; if(y < 0 || x < 0 || y < x) return 0; y %= mod; if(!y || !x) return 1; rep(i, 0, x-1) ans = ans * (y-i) % mod; rep(i, 1, x) ans = ans * Pow(i, mod-2) % mod; return ans; }
/*==================================================*/

int n, k, a[N];
ll dp[M], sum[M];

int main() {
   ms(dp, 0);
   // 利用滚动数组优化掉了第i个人这一维度
   dp[0] = 1;
   scanf("%d %d", &n, &k);
   rep(i, 1, n) scanf("%d", &a[i]);
   rep(i, 1, n) {
      ms(sum, 0);
      rep(j, 0, k) {
         int l = j+1, r = j + min(k - j, a[i]);
         if(l > r) break;
         // 差分前缀和优化
         sum[l] = (sum[l] + dp[j]) % mod;
         sum[r+1] -= dp[j];
         if(sum[r+1] < 0) sum[r+1] += mod;

      }
      rep(j, 1, k) {
         sum[j] = (sum[j] + sum[j-1]) % mod;
         dp[j] = (dp[j] + sum[j]) % mod;
      }
   }
   printf("%lld\n", dp[k]);
   return 0;
}