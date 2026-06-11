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
const int N = 20;
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

int n, a[N][N];
VI g[1<<17];
LL val[1<<17], f[1<<17];

int main() {
    FIO;
    cin >> n;
    rep(i, 0, n-1) rep(j, 0, n-1) cin >> a[i][j];
    int lim = (1 << n) - 1;
    rep(i, 0, lim) rep(j, 0, n-1) if(i >> j & 1) g[i].pb(j);
    rep(i, 0, lim) {
        rep(j, 0, g[i].size()-1) rep(k, j+1, g[i].size()-1) val[i] += a[g[i][j]][g[i][k]];
    }
    rep(i, 0, lim) {
        for(int s = i; s; s = ((s-1) & i)) chkmax(f[i], f[s] + val[i ^ s]);
        chkmax(f[i], val[i]);
    }
    cout << f[lim] << endl;

    return 0;
}