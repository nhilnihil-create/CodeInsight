#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n, m, a[N], b[N], c[N];
bool vis[N];
long long value[N];
vector<pair<int, int> > V[N];

long long mn = 1e18;
long long mx = -1e18;

void DFS(int w) {
    mn = min(mn, value[w]);
    mx = max(mx, value[w]);
    vis[w] = true;
    for (int i = 0; i < (int)V[w].size(); i++) {
        int u = V[w][i].first;
        int weight = V[w][i].second;
        if (!vis[u]) {
            value[u] = value[w] + weight;
            DFS(u);
        }
    }
}

int main() {
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        V[a[i]].push_back({b[i], c[i]});
        V[b[i]].push_back({a[i], -c[i]});
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            mn = 1e18;
            mx = -1e18;
            DFS(i);
            if (mx - mn > 1e9) {
                printf("No\n");
                return 0;
            }
        }
    }
    
    for (int i = 1; i <= m; i++) {
        if (value[b[i]] - value[a[i]] != c[i]) {
            printf("No\n");
            return 0;
        }
    }
    
    printf("Yes\n");
    
    return 0;
}