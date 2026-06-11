#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, L[200010], R[200010], D[200010];
long long ans[maxn];
vector<pair<int, int>> G[maxn];
bool used[maxn];

void dfs(int v) {
    used[v] = 1;
    for (auto p : G[v]) {
        if (used[p.first]) continue;
        ans[p.first] = ans[v] + p.second, dfs(p.first);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &L[i], &R[i], &D[i]);
        G[L[i]].push_back({R[i], D[i]});
        G[R[i]].push_back({L[i], -D[i]});
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) dfs(i);
    }
    for (int i = 1; i <= m; i++) {
        if (ans[R[i]] - ans[L[i]] != D[i]) printf("No\n"), exit(0);
    }
    printf("Yes\n");
    return 0;
}