#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;
char s[kN];
vector<int> g[kN];
bool pushed[kN];
int c[kN][2];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    scanf("%s", s);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        ++c[u][s[v] - 'A'];
        ++c[v][s[u] - 'A'];
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (c[i][0] == 0 || c[i][1] == 0) {
            pushed[i] = true;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int u : g[x]) {
            if (pushed[u]) continue;
            --c[u][s[x] - 'A'];
            if (c[u][0] == 0 || c[u][1] == 0) {
                pushed[u] = true;
                q.push(u);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!pushed[i]) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
