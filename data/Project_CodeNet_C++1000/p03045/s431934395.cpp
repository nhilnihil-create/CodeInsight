#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 100005;
vector <int> v[N];
bool vis[N];

void dfs(int x) {
    vis[x] = true;
    for (int y : v[x]) {
        if (!vis[y]) {
            dfs(y);
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        v[x].pb(y);
        v[y].pb(x);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i);
        }
    }
    printf("%d", cnt);
    return 0;
}
