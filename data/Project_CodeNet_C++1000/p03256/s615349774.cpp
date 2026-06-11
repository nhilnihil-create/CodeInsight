#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, cnt[maxn][2];
vector<int> G[maxn];
char s[maxn];

int main() {
    scanf("%d %d %s", &n, &m, s + 1);
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d %d", &u, &v);
        cnt[u][s[v] - 'A']++, cnt[v][s[u] - 'A']++;
        G[u].push_back(v), G[v].push_back(u);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!cnt[i][0] || !cnt[i][1]) q.push(i);
    }
    int num = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop(), num++;
        for (int u : G[v]) {
            if (!cnt[u][0] || !cnt[u][1]) continue;
            cnt[u][s[v] - 'A']--;
            if (!cnt[u][0] || !cnt[u][1]) q.push(u);
        }
    }
    printf("%s\n", num == n ? "No" : "Yes");
    return 0;
}