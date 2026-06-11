#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

typedef long long Int;

struct edge {Int to, cost;};

vector<vector<edge>> G(100010);
vector<int> cn(100010);

void dfs(Int now, Int par = -1) {
    int n = cn[now];
    for (edge e : G[now]){
        if (e.to == par) continue;
        if (e.cost % 2 == 1) {
            cn[e.to] = (n + 1) % 2;
        }
        else cn[e.to] = n;
        dfs(e.to, now);
    }
    return;
}


int main() {

    Int N;
    cin >> N;
    rep(i,N-1) {
        Int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    cn[0] = 0;
    dfs(0);

    rep(i,N) cout << cn[i] << endl;

    return 0;
}
