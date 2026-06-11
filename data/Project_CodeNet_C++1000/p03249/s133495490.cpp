#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MN = 100010;

int N;
ll D[MN];
vector<pair<ll, int> > ord;
int inv[MN], sz[MN];
vector<pii> edge;
vector<int> adj[MN];
int dep[MN];

void dfs(int u, int p) {
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%lld", &D[i]);
        ord.push_back({ D[i], i });
    }

    sort(ord.begin(), ord.end());
    for(int i = 0; i < N; i++) inv[i] = ord[i].second;
    sort(D, D + N);

    for(int i = 0; i < N; i++) sz[i] = 1;
    for(int i = N - 1; i >= 1; i--) {
        if(2 * sz[i] >= N) {
            printf("-1");
            return 0;
        }
        if(D[i] - N + 2 * sz[i] <= 0) {
            printf("-1");
            return 0;
        }
        int a = lower_bound(D, D + N, D[i] - N + 2 * sz[i]) - D;
        if(D[a] != D[i] - N + 2 * sz[i]) {
            printf("-1");
            return 0;
        }

        edge.push_back(pii(inv[a], inv[i]));
        sz[a] += sz[i];
        adj[a].push_back(i);
    }
    if(sz[0] != N) {
        printf("-1");
        return 0;
    }

    dfs(0, -1);

    ll sum = 0;
    for(int i = 0; i < N; i++) sum += dep[i];
    if(sum != D[0]) {
        printf("-1");
        return 0;
    }

    for(int i = 0; i < N - 1; i++) {
        printf("%d %d\n", edge[i].first + 1, edge[i].second + 1);
    }
}
