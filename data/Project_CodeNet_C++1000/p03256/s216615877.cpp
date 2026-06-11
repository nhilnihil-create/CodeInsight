#include<bits/stdc++.h>

using namespace std;

#define pb push_back

const int N = 2e5 + 5;
int n, m, deg[N][2];
string s;
vector<int> gr[N], vec;
bool in[N];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s; s = '*' + s;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        gr[u].pb(v); gr[v].pb(u);
        deg[u][ s[v] - 'A' ] ++;
        deg[v][ s[u] - 'A' ] ++;
    }

    for (int u = 1; u <= n; ++u) if (!deg[u][0] || !deg[u][1]) in[u] = 1, vec.pb(u);

    for (int i = 0; i < vec.size(); ++i) {
        int u = vec[i];
        for (int v : gr[u]) {
            deg[v][ s[u] - 'A' ] --;
            if ( (!deg[v][0] || !deg[v][1]) && !in[v]) in[v] = 1, vec.pb(v);
        }
    }

    if (vec.size() == n) cout << "No";
    else cout << "Yes";

    return 0;
}
