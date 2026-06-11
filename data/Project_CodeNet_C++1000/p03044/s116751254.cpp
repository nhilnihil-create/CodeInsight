#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;


typedef vector<vector<int>> Graph;

Graph G;
unordered_map<int, unordered_map<int, int>> W;
vector<int> d;

void dfs(int node, int parent) {
    if (parent < 0) {
        d[node] = 0;
    }
    else if (W[parent][node] % 2 == 0) {
        d[node] = d[parent];
    }
    else {
        d[node] = 1 - d[parent];
    }

    for (int to: G[node]) {
        if (to == parent) continue;
        dfs(to, node);
    }
}

void Main()
{
    ll n;
    cin >> n;

    vector<ll> u(n-1), v(n-1), w(n-1);
    rep(i, n-1) cin >> u[i] >> v[i] >> w[i];
    
    G.assign(n, vector<int>());
    rep(i, n) W[i] = unordered_map<int, int>();
    d.assign(n, 0);
    rep(i, n - 1) {
        G[u[i] - 1].push_back(v[i] - 1);
        G[v[i] - 1].push_back(u[i] - 1);
        W[u[i] - 1][v[i] - 1] = w[i];
        W[v[i] - 1][u[i] - 1] = w[i];
    }

    dfs(0, -1);

    rep(i, n) {
        put(d[i]);
    }
}
signed main(){ Main();return 0;}