#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ll N, M;
using Graph = vector<Vi>;
Graph g;
int indeg[100010];
int par[100010];
int used[100010];

void solve() {
    cin >> N >> M;
    g.resize(N);
    for (ll i = 0; i < N - 1 + M; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v);
        ++indeg[v];
    }

    int root;
    for (ll i = 0; i < N; i++) {
        if (indeg[i] == 0) {
            root = i;
            break;
        }
    }

    for (ll i = 0; i < N; i++) {
        par[i] = -1;
    }
    par[root] = root;

    queue<int> q;
    q.emplace(root);
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        for (const auto& v : g[idx]) {
            par[v] = idx;
            --indeg[v];
            if (indeg[v] == 0) {
                q.emplace(v);
            }
        }
    }

    for (ll i = 0; i < N; i++) {
        if (i == root) {
            cout << 0 << "\n";
        }
        else {
            cout << par[i] + 1 << "\n";
        }
    }
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif
#ifdef FILEOUTPUT
    ofstream ofs("./in_out/output.txt");
    cout.rdbuf(ofs.rdbuf());
#endif
    solve();
    cout << flush;
    return 0;
}