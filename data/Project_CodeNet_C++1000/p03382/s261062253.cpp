// Date: 2020-04-27

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
#define IO freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout)
#define FIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define D(x) cout << #x << " = " << x << endl;
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)x.size())
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const LL mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

int a[N], n;
int main() {
    FIO;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    sort(a+1, a+1+n);
    int ans1 = a[n], ans2 = a[1], cur = min(abs(a[1]-a[n]/2), abs(a[1]-(a[n]+1)/2));
    rep(i, 2, n-1) {
        int tp = min(abs(a[i]-a[n]/2), abs(a[i]-(a[n]+1)/2));
        if(tp < cur) ans2 = a[i], cur = tp;
    }
    cout << ans1 << " " << ans2;


    return 0;
}