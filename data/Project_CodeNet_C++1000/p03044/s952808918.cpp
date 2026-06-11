#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define ALL(a) a.begin(),a.end()
#define INIT(a,b) memset(a,b,sizeof(a))
using lint = long long int;

struct Edge { int v, w; };

int N;
vector<Edge> edge[100005];
int ans[100005];

void dfs(int v, int p) {
    for (const Edge& e : edge[v]) {
        if (e.v == p) continue;
        ans[e.v] = (e.w % 2 ? 1 - ans[v] : ans[v]);
        dfs(e.v, v);
    }
}

int main() {
    cin >> N;
    for_(i,0,N-1) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    ans[0] = 0;
    dfs(0, -1);
    for_(i,0,N) cout << ans[i] << endl;
}