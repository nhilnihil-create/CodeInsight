// Date: 2020-02-27

#include <bits/stdc++.h>
#include <stdio.h>
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

int n, k, q;
int a[N], b[N], c[N], tot, ans;

void add(int l, int r) {
    int len = r-l+1;
    rep(i, 1, len) b[i] = a[i+l-1];
    sort(b+1, b+1+len);
    rep(i, 1, len-k+1) c[++tot] = b[i];
}

void solve(int x) {
    tot = 0;
    int pre = 1;
    rep(i, 1, n+1) if(a[i] < x) {
        if(pre <= i-1) add(pre, i-1);
        pre = i+1;
    }
    sort(c+1, c+1+tot);
    if(tot < q) return;
    chkmin(ans, c[q]-c[1]);
}

int main() {
    scanf("%d%d%d", &n, &k, &q);
    rep(i, 1, n) scanf("%d", &a[i]);
    a[n+1] = 0;
    ans = inf;
    rep(i, 1, n) solve(a[i]);
    printf("%d\n", ans);

    return 0;
}