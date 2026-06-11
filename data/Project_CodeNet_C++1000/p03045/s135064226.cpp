#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

const int N = 1e5 + 10;
struct Edge { int v, next;} edge[N * 4];
bool vis[N];
int n, m, cnt, head[N];
inline void add(int u, int v) {
    edge[++cnt].v = v; edge[cnt].next = head[u]; head[u] = cnt++;
    edge[++cnt].v = u; edge[cnt].next = head[v]; head[v] = cnt++;
}
void dfs(int u) {
    vis[u] = 1;
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (!vis[v]) dfs(v);
    }
}

int main() {
    n = read(), m = read();
    for (int i = 0; i < m; i++) {
        int a = read(), b = read(); int c = read();
        add(a, b);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans++;
            dfs(i);
        }
    }
    printf("%d\n", ans);
    return 0;
}