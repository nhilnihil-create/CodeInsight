#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
vector<int> g[200005];

int d[200005];

void dfs(int u, int dist) {
    d[u] = dist;
    for (int v : g[u]) {
        if (d[v] == -1) {
            dfs(v, dist + 1);
        }
    }
}

int diameter() {
    memset(d + 1, -1, sizeof(int) * n);
    dfs(1, 0);
    int v = 1;
    for (int u = 2; u <= n; ++u)
        if (d[u] > d[v]) v = u;
    memset(d + 1, -1, sizeof(int) * n);
    dfs(v, 0);
    int dia = 0;
    for (int u = 1; u <= n; ++u) dia = max(dia, d[u]);
    return dia;
}

int main() {
    // freopen("data.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int d = diameter();
    if (d % 3 == 1) {
        printf("Second\n");
    } else {
        printf("First\n");
    }
}