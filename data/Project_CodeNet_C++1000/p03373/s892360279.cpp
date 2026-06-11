// Date: 2020-02-29

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
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

int main() {
    int a, b, c, x, y;
    scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
    int ans = inf;
    rep(i, 0, x) {
        int tp = i * a;
        if(i < x) {
            tp += 2*c*(x-i);
            int ry = y-(x-i);
            if(ry > 0) tp += min(ry * b, 2 * ry * c);
        } else tp += min(y * b, 2 * y * c);
        ans = min(ans, tp);
    }
    printf("%d\n", ans);

    return 0;
}