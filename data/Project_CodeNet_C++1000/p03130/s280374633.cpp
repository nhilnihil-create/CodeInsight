#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cstring>

//#define INF 1000000000;
#define MOD 1000000007;
#define LIMIT 1000000000000000000;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define int long long
typedef pair<int, int> P;

struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} SETUP;

template<class T>
bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const ll INF = 1LL << 60;

class Edge {
private:
    int m_from, m_to, m_cost;

public:
    Edge(int f, int t, int c = 1) :
        m_from(f), m_to(t), m_cost(c) {}

    int from() const {
        return m_from;
    }

    int to() const {
        return m_to;
    }

    int cost() const {
        return m_cost;
    }

    Edge& operator=(const int x) {
        m_cost = x;
        return *this;
    }

    bool operator<(const Edge& e) const {
        return m_cost < e.cost();
    }
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;

// 全点間最短路を求める。到達できない要素にはinfが格納されている前提。
void warshall_floyd(Graph& graph, int inf) {
    const int v = graph.size();
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                //if (i == j || i == k || j == k) continue; // 自分と同じノードに対する距離に0を格納していたらこの処理は不要。
                if (graph[i][k].cost() == inf || graph[k][j].cost() == inf) continue;
                graph[i][j] = min(graph[i][j].cost(), graph[i][k].cost() + graph[k][j].cost());
            }
        }
    }
}

// 隣接行列を生成
Graph gen_graph(const int n, const int inf) {
    Graph g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cost = (i == j) ? 0 : inf;
            g[i].push_back(Edge(i, j, cost));
        }
    }
    return g;
}

signed main() {
    auto graph = gen_graph(4, INF);
    for (int i = 0; i < 3; i++) {
        int a, b; cin >> a >> b; a--, b--;
        graph[a][b] = graph[b][a] = 1;
    }
    warshall_floyd(graph, INF);

    bool ok = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (graph[i][j].cost() == 3) {
                ok = true;
            }
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}