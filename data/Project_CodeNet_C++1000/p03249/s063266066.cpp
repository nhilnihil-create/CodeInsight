/// IN THE NAME OF METAL
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef pair<ll, ll> pll;
 
#define sz(x)                       (ll) x.size()
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second

ll Pow(ll a, ll b, ll md, ll ans = 1) {
    for (; b; b >>= 1, a = a * a % md)
        if (b & 1)
            ans = ans * a % md;
    return ans % md;
}
const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7;
ll Sz[MAXN], H[MAXN], n;
pll D[MAXN]; vector<ll> adj[MAXN]; map<ll, ll> pos;

void DFS(ll v, ll p = -1) {
    for (ll u : adj[v]) {
        H[u] = H[v] + 1;
        DFS(u, v);
    }
}

int main() {
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &D[i].F);
        D[i].S = i;
        pos[D[i].F] = i;
    }
    sort(D + 1, D + n + 1, greater<pll>());
    for (ll i = 1; i <= n - 1; i++) {
        ll v = D[i].S;
        pos.erase(D[i].S);
        Sz[v] = 1;
        for (ll u : adj[v]) {
            Sz[v] += Sz[u];
        }
        if (pos.find(D[i].F - n + 2 * Sz[v]) == pos.end()) break;
        ll par = pos[D[i].F - n + 2 * Sz[v]];
        adj[par].push_back(v);
    }
    DFS(D[n].S);
    if (accumulate(H, H + MAXN, 0LL) != D[n].F) printf("-1\n");
    else {
        for (ll i = 1; i <= n; i++) {
            for (ll u : adj[i]) printf("%lld %lld\n", i, u);
        }
    }
    return 0;
}

