// Date: 2020-08-28

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

int p[N], n, m;
LL dis[N];

int Find(int x) {
    if(x != p[x]) {
        int rt = Find(p[x]);
        dis[x] += dis[p[x]];
        p[x] = rt;
    }
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, 1, n) p[i] = i;
    int flag = 1;
    while(m--) {
        int x, y, d;
        scanf("%d%d%d", &x, &y, &d);
        int fx = Find(x), fy = Find(y);
        if(fx != fy) {
            p[fx] = fy;
            dis[fx] = d + dis[y] - dis[x];
        } else {
            if(dis[x]-dis[y] != d) {
                flag = 0;
            }
        }
    }
    if(flag) puts("Yes");
    else puts("No");

    return 0;
}