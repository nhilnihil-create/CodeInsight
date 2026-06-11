// Date: 2020-02-26

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
const int N = 1e5 + 10;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

LL ans[N], fac[20];
int sz;

int get(LL x) {
    int ans = 0;
    while(x) ans += x % 10, x /= 10;
    return ans;
}

void init() {
    fac[0] = 1;
    rep(i, 1, 15) fac[i] = fac[i-1] * 10;
    ans[++sz] = fac[15]-1;
    while(1) {
        LL tp = ans[sz];
        LL mx = 0;
        rep(i, 0, 15) rep(j, 1, 9) {
            if(tp > fac[i] * j) {
                LL tp2 = tp - fac[i] * j;
                if(tp2 * get(tp) <= tp * get(tp2)) {
                    mx = max(mx, tp2);
                }
            }
        }
        if(mx == 0) break;
        ans[++sz] = mx;
    }
}

int main() {
    init();
    int k; scanf("%d", &k);
    while(k--) printf("%lld\n", ans[sz--]);

    return 0;
}