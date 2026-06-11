#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m, deg[N][2];
vector <int> g[N], same;
string s;
bool in[N];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s; memset(in, 0, sizeof(in)); s = "#" + s;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u][s[v] - 'A']++; deg[v][s[u] - 'A']++;
    }

    for (int i = 1; i <= n; i++) {
        if (!deg[i][0] || !deg[i][1]) {
            in[i] = true;
            same.push_back(i);
        }
    }

    for (int i = 0; i < same.size(); i++) {
        int u = same[i];
        for (int v: g[u]) {
            deg[v][s[u] - 'A']--;
            if (!deg[v][0] || !deg[v][1]) {
                if (!in[v]) {
                    in[v] = true;
                    same.push_back(v);
                }
            }
        }
    }

    if (same.size() != n) cout << "Yes";
    else cout << "No";
    return 0;
}
