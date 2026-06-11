#include <bits/stdc++.h>

using namespace std;
struct Edge {
    int next, to;
} edge[200005 << 1];
int head[200005], n, ss, vis[200005], minn;

inline void add(int x, int y) {
    static int cnt = 1;
    edge[cnt].to = y, edge[cnt].next = head[x], head[x] = cnt++;
}

void DFS(int x, int s) {
    if (s > minn)minn = s, ss = x;
    for (int i = head[x]; i; i = edge[i].next) {
        if (vis[edge[i].to] == 0)vis[edge[i].to] = 1, DFS(edge[i].to, s + 1);
    }
}

queue<int> que;

int main() {
    cin >> n;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    DFS(1, 0), minn = 0, memset(vis, 0, sizeof(vis)), DFS(ss, 0);
    if ((minn + 1) % 3 == 2)cout << "Second";
    else cout << "First";
    return 0;
}