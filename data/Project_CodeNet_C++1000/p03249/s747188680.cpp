#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int N = 1e5 + 5;

int n;
ll D[N];
pli a[N];
int sz[N];

vector <int> g[N];

void add(int x, int y) {
    sz[x] += sz[y];
    g[x].push_back(y);
}

ll res;

void dfs(int u, int fa, ll d) {
    res += d;
    for(auto v : g[u]) {
        if(v != fa) dfs(v, u, d + 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> D[i];
    for(int i = 1; i <= n; i++) {
        a[i] = MP(D[i], i); sz[i] = 1;
    }
    sort(a + 1, a + n + 1);
    int f = 1;
    for(int i = n; i > 1 && f; i--) {
        ll t = a[i].fi + 2ll * sz[a[i].se] - n;
        int x = lower_bound(a + 1, a + i, MP(t, 0)) - a;
        if(a[x].fi != t) f = 0;
        add(a[x].se, a[i].se);
    }
    if(f == 0) {cout << -1; return 0;}
    dfs(a[1].se, 0, 0);
    if(res != a[1].fi) {cout << -1; return 0;}
    for(int i = 1; i <= n; i++) {
        for(auto it : g[i]) cout << i << ' ' << it << '\n';
    }
    return 0;
}
