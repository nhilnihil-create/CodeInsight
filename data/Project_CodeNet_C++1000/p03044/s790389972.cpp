#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 100005;
vector <pair <int, int> > v[N];
int res[N];

void dfs(int x, int par, ll col) {
    res[x] = col & 1;
    for (auto y : v[x]) {
        if (y.fi != par) {
            dfs(y.fi, x, col + y.se);
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        v[x].pb({y, w});
        v[y].pb({x, w});
    }
    dfs(1, 1, 0);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}
