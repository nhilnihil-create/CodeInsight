
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
int n, u, v, w;
int res[N];
vector<ii> e[N];

void dfs(int uu, int c, int par) {
    res[uu] = c;
    for (auto &p : e[uu]) {
        int vv = p.first;
        int ww = p.second;
        if (vv == par) continue;
        if (ww & 1) {
            dfs(vv, 1 - c, uu);
        } else {
            dfs(vv, c, uu);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << endl;
    }

    return 0;
}

