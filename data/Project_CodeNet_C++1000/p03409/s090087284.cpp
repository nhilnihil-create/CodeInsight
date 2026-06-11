#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#include<map>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
typedef long long ll;
typedef long double ld;
const ll MOD =  1000000007;
struct edge {
    int to, cap, rev;// 行先　容量　逆辺
};
vector<edge> g[1010]; bool used[1010];
void add(int u, int v, int f) {
    g[u].push_back(edge{ v,f,(int)g[v].size() });
    g[v].push_back(edge{ u,0,(int)g[u].size() - 1 });
}
int dfs(int pos, int to, int f) {
    if (pos == to) return f;
    used[pos] = 1;
    rep(i, g[pos].size()) {
        if (g[pos][i].cap == 0 || used[g[pos][i].to]) continue;
        int D = dfs(g[pos][i].to, to, min(g[pos][i].cap, f));
        if (D >= 1) {
            g[pos][i].cap -= D;
            g[g[pos][i].to][g[pos][i].rev].cap += D;
            return D;
        }
    }return 0;
}
int max_flow(int s, int t) {
    int F = 0; for (;;) {
        fill(used, used + 1001, 0);
        int F2 = dfs(s, t, (1e9));
        F += F2;
        if (F2 == 0) return F;
    }return MOD;
}
int n, m, a[1000], b[1000], c[110],d[110],E;
int main() {
    cin >> n;
    req(i, n) add(0, i, 1);
    req(i, n) add(i + n, 2 * n+1, 1);
    req(i, n) cin >> a[i] >> b[i];
    req(i, n) cin >> c[i] >> d[i];
    req(i, n) {
        req(j,n) {
            if (a[i] < c[j] && b[i] < d[j]) {
                add(i, j + n, 1);
            }
        }
    }
    cout << max_flow(0, n * 2+1) << endl;
}