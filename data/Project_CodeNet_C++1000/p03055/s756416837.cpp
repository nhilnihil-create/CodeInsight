#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int head[maxn], tot = 1;
int Next[maxn << 1], to[maxn << 1];
void add(int u, int v) {
    to[tot] = v, Next[tot] = head[u];
    head[u] = tot++;
}
int n;
int deep[maxn];
int bfs(int s) {
    queue<int> Q;
    memset(deep, 0, sizeof deep);
    deep[s] = 1;
    Q.push(s);
    int ans = s;
    while (!Q.empty()) {
        int u = ans = Q.front();
        Q.pop();
        for (int i = head[u]; i; i = Next[i])
            if (!deep[to[i]]) {
                deep[to[i]] = deep[u] + 1;
                Q.push(to[i]);
            }
    }
    return ans;
}
int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    int cnt = deep[bfs(bfs(1))];
    printf("%s\n", cnt % 3 == 2 ? "Second" : "First");
    return 0;
}