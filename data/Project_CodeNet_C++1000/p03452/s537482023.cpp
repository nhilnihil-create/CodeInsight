#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

struct Graph {
    int V, E;
    static const int MAX_V = 100100;//書き換え!
    vector<pii> G[MAX_V];
    int x[MAX_V];
    bool left[MAX_V];
    bool used[MAX_V];

    Graph(int V, int E) : V(V), E(E) {
        rep(i, MAX_V) {
            x[i] = -1;
            left[i] = true;
            used[i] = false;
        }
    }

    Graph() {}

    void init(int v, int e) {
        V = v, E = e;
        rep(i, MAX_V) {
            x[i] = -1;
            left[i] = true;
            used[i] = false;
        }
    }

    //a->b有向(コストc)
    void addEdge(int a, int b, int c) {
        G[a].emplace_back(b, c);
        left[b] = false;
    }

    bool check(int v, int prev, int d) {
        used[v] = true;
        if (x[v] == -1) {
            x[v] = x[prev] + d;
            rep(i, G[v].size()) {
                int to = G[v][i].first;
                int d2 = G[v][i].second;
                if (!check(to, v, d2))return false;
            }
            return true;
        } else {
            if (x[v] != x[prev] + d)return false;
            else return true;
        }
    }

    bool check(int v) {
        if (!left[v])return true;
        if (used[v])return true;
        used[v] = true;
        x[v] = 5000000000000000000;
        rep(i, G[v].size()) {
            int to = G[v][i].first;
            int d = G[v][i].second;
            if (!check(to, v, d))return false;
        }
        return true;
    }

    //checkが全て終わった後に検査されていない頂点がある
    bool hasLoop() {
        rep(i, V) {
            if (!used[i])return true;
        }
        return false;
    }
};

Graph g;

signed main() {
    int N, M;
    cin >> N >> M;
    g.init(N, M);
    rep(i, M) {
        int l, r, d;
        cin >> l >> r >> d;
        --l, --r;
        g.addEdge(l, r, d);
    }
    rep(i, N) {
        if (!g.check(i)) {
            cout << "No" << endl;
            return 0;
        }
    }
    if (g.hasLoop())cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
