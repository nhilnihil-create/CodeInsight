#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define y1 y114514
#define elif else if
#define y2 y1919810
typedef pair <int, int> PII;
typedef vector <int> VI;
//#define int long long
#define all(x) x.begin(),  x.end()
#define lsh(i) (1 << (i))
#define lshll(i) (1LL << (i))
#define repn(i, n) for (int i = 1; i <= (int)n; i++)
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define range(i, s, t)  for (int i = s; i <= (int)t; i++)
const int INF = 0x3f3f3f3f;
const long double EPS = 1e-6;
long long qread() {
    char c = getchar();
    int neg = 1;
    long long val = 0;
    while (c != '-' && !isdigit(c)) c = getchar();
    if (c == '-') c = getchar(), neg = -1;
    while (isdigit(c)) val = (val << 3) + (val << 1) + c - '0', c = getchar();
    return neg * val;
}
const int N = 200020;
vector <int> G[N];
int n, m;
bool vis[N]; int low[N]; int dep[N];
void getDepth(int u, int f) {
//    fprintf(stderr, "getDepth(%d, %d)\n", u, f);
    vis[u] = true;
    if (f != -1) dep[u] = dep[f] + 1;
    rep(i, G[u].size()) {
        int v = G[u][i];
        if (v != f && !vis[v]) getDepth(v, u);
    }
}
void findBridge(int u, int f) {
//    fprintf(stderr, "findBridge(%d, %d)\n",u, f);
    low[u] = dep[u];
    vis[u] = true;
    rep(i, G[u].size()) {
        int v = G[u][i];
        if (v != f) {
            if (!vis[v]) findBridge(v, u);
//            fprintf(stderr, "low[%d] = %d\n", v, low[v]);
            low[u] = min(low[u], low[v]);
        }

    }
}
void solve() {
    n = qread(); m = qread();
    rep(i, m) {
        int u = qread(), v = qread();
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    getDepth(0, -1);
//    rep(i, n) fprintf(stderr, "%d ", dep[i]);
    memset(vis, 0, sizeof vis);
    findBridge(0, -1);
    int nBridges = 0;
//    rep(i, n) fprintf(stderr, "%d ", low[i]);
    rep(i, n) if (low[i] == dep[i]) nBridges++;
    printf("%d\n", nBridges - 1);
}
int main() {
    int T = 1;
    //T = qread();
    while (T--) solve();
    return 0;
}
