#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int h, w, n, x[maxn], y[maxn];
vector<int> G[maxn];
bool chk[maxn];

int main() {
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]), G[y[i]].push_back(x[i]);
    }
    for (int i = 1; i <= w; i++) {
        G[i].push_back(h + 1);
    }
    sort(G[1].begin(), G[1].end());
    int ans = G[1][0] - 1, t = 0;
    for (int i = 2; i <= w; i++) {
        sort(G[i].begin(), G[i].end());
        int mx = 0;
        for (int j = 0; j < G[i].size(); j++) {
            if (G[i][j] <= i + t || chk[G[i][j] - 1]) {
                chk[G[i][j]] = 1, mx = max(mx, G[i][j]);
            } else {
                ans = min(ans, G[i][j] - 1); break;
            }
        }
        t = max(t, mx - i + 1);
    }
    printf("%d\n", ans);
    return 0;
}