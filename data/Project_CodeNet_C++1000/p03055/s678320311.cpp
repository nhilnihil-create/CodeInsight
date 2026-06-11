#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, d[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int v, int f) {
        d[v] = d[f] + 1;
        for (int u : G[v]) if (u ^ f) dfs(u, v);
    };
    dfs(1, 0);
    int v = max_element(d + 1, d + n + 1) - d;
    dfs(v, 0);
    int l = *max_element(d + 1, d + n + 1);
    printf("%s\n", l % 3 == 2 ? "Second" : "First");
    return 0;
}