#include<bits/stdc++.h>
#define ll            long long
#define pb            emplace_back
#define fi            first
#define se            second
#define mp            make_pair
//#define int           int64_t

using namespace std;

typedef pair<int, int> pii;
const int N = (int)2e5 + 10;

int n, m, u, v, in[N], id[N], cnt;
vector<int> adj[N], rev[N];
queue<int> q;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FileName      "test"
    if(fopen(FileName".inp", "r")) {
       freopen(FileName".inp", "r", stdin);
       freopen(FileName".out", "w", stdout);
    }
    cin >> n >> m; m += n - 1;
    for(int i = 1; i <= m; ++i) {
        cin >> u >> v;
        adj[u].pb(v); ++in[v];
        rev[v].pb(u);
    }
    for(int i = 1; i <= n; ++i)
        if(in[i] == 0) {q.push(i); break;}
    while(q.size()) {
        id[u = q.front()] = ++cnt; q.pop();
        for(int v: adj[u])
            if(--in[v] == 0) q.push(v);
    }
    int res = 0;
    for(int i = 1; i <= n; ++i) {
        res = 0;
        for(int u: rev[i])
            if(id[u] > id[res]) res = u;
        cout << res << '\n';
    }
}
