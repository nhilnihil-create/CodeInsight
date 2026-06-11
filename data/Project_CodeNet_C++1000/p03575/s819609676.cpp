
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 55;
int n, m, a, b;
vector<int> e[N];
int dfu[N], low[N];
int vt, ans;

void dfs(int par, int x) {
    if (dfu[x] != 0) return;
    dfu[x] = vt;
    low[x] = vt;
    ++vt;
    for (int y : e[x]) {
        if (y == par) continue;
        dfs(x, y);
        low[x] = min(low[x], low[y]);
        if (low[y] > dfu[x])
            ++ans;
    }
}

int main() {
    vt = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        e[a - 1].push_back(b - 1);
        e[b - 1].push_back(a - 1);
    }

    dfs(-1, 0);
    cout << ans << endl;

    return 0;
}

