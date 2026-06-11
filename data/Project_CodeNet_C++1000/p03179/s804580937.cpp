// Date: 2020-03-16

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
#define FIO ios::sync_with_stdio(false);cin.tie(0)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const LL mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 3000 + 10;
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

int n;
char s[N];
LL dp[2][N], pre[2][N];

int main() {
    scanf("%d%s", &n, s+1);
    dp[0][1] = pre[0][1] = 1;
    int cur = 1;
    rep(i, 2, n) {
        rep(j, 1, i) {
            if(s[i-1] == '<') {
                if(j == 1) dp[cur][j] = 0;
                else dp[cur][j] = pre[cur^1][j-1];
            } else {
                if(j == i) dp[cur][j] = 0;
                else dp[cur][j] = (pre[cur^1][i-1]-pre[cur^1][j-1]+mod)%mod;
            }
        }
        rep(j, 1, i) pre[cur][j] = (pre[cur][j-1] + dp[cur][j]) % mod;
        cur ^= 1;
    }
    LL ans = 0;
    rep(i, 1, n) ans = (ans + dp[cur^1][i]) % mod;
    printf("%lld\n", ans);

    return 0;
}