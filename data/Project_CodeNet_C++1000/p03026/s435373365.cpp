#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = std::pair<int, int>;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back
const int mn = 1e5 + 5;

int n;
vector<int> g[mn];
int deg[mn];

vector<int> v;
ll ans = 0;
ll a[mn];
int cur = 0;

void topo() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        a[u] = v[cur++];
        for (auto &i:g[u]) {
            if (a[i]) ans += a[i];
            deg[i]--;
            if (deg[i]==1){
                q.push(i);
            }
        }
    }
}

int main() {
#ifdef trote
    freopen("../1.txt", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    for (int i = 1; i <= n; i++) {
        int u;
        scanf("%d", &u);
        v.pb(u);
    }
    sort(all(v));
    topo();
    printf("%lld\n", ans);
    for (int i = 1; i < n; i++) printf("%d ", a[i]);
    printf("%d\n", a[n]);
    return 0;
}