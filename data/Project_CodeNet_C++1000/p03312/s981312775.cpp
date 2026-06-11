// Date: 2020-02-25

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
const int N = 2e5 + 10;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

int cutL[N], cutR[N];
LL sum[N], a[N], b[4];

int main() {
    int n; scanf("%d", &n);
    rep(i, 1, n) scanf("%lld", &a[i]), sum[i] = sum[i-1] + a[i];
    int l = 1;
    cutL[2] = l;
    rep(i, 3, n) {
        LL x = sum[l], y = sum[i] - x;
        while(abs(y-x) > abs(x+a[l+1]-(y-a[l+1])) && l+1 < i) x += a[l+1], y -= a[l+1], ++l;
        cutL[i] = l;  
    }
    int r = n;
    cutR[n-1] = r;
    per(i, n-2, 1) {
        LL x = sum[n]-sum[r-1], y = sum[n]-sum[i-1]-x;
        while(abs(y-x) > abs(x+a[r-1]-(y-a[r-1])) && r-1 > i) x += a[r-1], y -= a[r-1], --r;
        cutR[i] = r;
    }
    LL ans = INF;
    rep(i, 2, n-2) {
        l = cutL[i], r = cutR[i+1];
        b[0] = sum[l], b[1] = sum[i]-b[0], b[2] = sum[n]-sum[r-1], b[3] = sum[n]-sum[i]-b[2];
        sort(b, b+4);
        ans = min(ans, b[3]-b[0]);
    }
    printf("%lld\n", ans);


    return 0;
}