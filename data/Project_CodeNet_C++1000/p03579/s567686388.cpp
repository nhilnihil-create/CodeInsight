#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;
vector<vector<ll>> G;
vector<ll> colors;
//頂点vから辺をちょうど3本たどる
bool is_bipartite(ll v, ll color = 0) {
    colors[v] = color;
    for (auto nv : G[v]) {
        if (colors[nv] == color) return false;
        else if (colors[nv] == -1 && !(is_bipartite(nv, 1-color))) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> N >> M;
    G.resize(N);
    colors.assign(N, -1);
    for (int i = 0; i < M; i++) {
        ll a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if (is_bipartite(0)) {
        ll B, W = 0;
        for (int i = 0; i < N; i++) {
            W += colors[i];
        }
        B = N-W;
        cout << B*W-M << endl;
    }
    else cout << N*(N-1)/2-M << endl;
}
