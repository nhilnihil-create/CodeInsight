#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ft first
#define sd second
#define pb push_back
using namespace std;
const ll mod = 1e9+7;
const ll inf = 1e9+9;
 
ll power(ll a, ll b, ll m = mod) {
    ll x = 1;
    while(b) {
        if(b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}
 
const int N = 10009;
vector<int> g[N];
int a[N], assign[N], f[N];
vector<pair<int, int>> nodes;
void dfs(int u, int par) {
    f[u] = 1;
    for(int v: g[u]) {
        if(v == par) continue;
        dfs(v, u);
        f[u] = max(f[u], f[v]+1);
    }
    nodes.push_back({f[u], u});
}
signed main() {  
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    dfs(1, 0);
    sort(nodes.begin(), nodes.end());
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        assign[nodes[i].second] = a[i+1];
        sum += a[i+1];
    }
    sum -= a[n];
    cout << sum << "\n";
    for(int i = 1; i <= n; i++) {
        cout << assign[i] << " ";
    }
    cout << "\n";



    return 0;
    
}