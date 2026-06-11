#include <bits/stdc++.h>
#define fst first
#define snd second
#define rep(n) for(lint I = 0; (I) < (lint)(n); ++(I))
#define repeat(i, n) for(lint i = 0; (i) < (lint)(n); ++(i))
#define repeat_to(i, n) for(lint i = 0; (i) <= (lint)(n); ++(i))
#define repeat_from(i, m, n) for(lint i = (m); (i) < (lint)(n); ++(i))
#define repeat_from_to(i, m, n) for(lint i = (m); (i) <= (lint)(n); ++(i))
#define repeat_reverse_from_to(i, m, n) for(lint i = (m); (i) >= (lint)(n); --(i))
#define el cout<<endl
#define dump(x) cout<<" "<<#x<<"="<<x
#define vdump(v) for(size_t I=0; I<v.size(); ++I){cout<<" "<<#v<<"["<<I<<"]="<<v[I];} cout<<endl
using namespace std;
using lint = long long;
using ld = long double;

/****************** グラフ ******************/
// 諸宣言
using Weight = lint;
using Flow = lint;
struct Edge {
    int src, dst;
    Weight weight;
    Flow cap;
    Edge() : src(0), dst(0), weight(0) {}
    Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
    Edge(int s, int d, Weight w, Flow c) : src(s), dst(d), weight(w), cap(c) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void add_edge(Graph &g, int a, int b, Weight w = 1, Flow c = 1) {
    g[a].emplace_back(a, b, w, c);
    g[b].emplace_back(b, a, w, c);
}
void add_arc(Graph &g, int a, int b, Weight w = 1, Flow c = 1) {
    g[a].emplace_back(a, b, w, c);
}

vector<Weight> dijkstra(const Graph &g, int s) {
    const Weight INF = numeric_limits<Weight>::max() / 8;
    using state = tuple<Weight, int>;
    priority_queue<state> q;
    vector<Weight> dist(g.size(), INF);
    dist[s] = 0;
    q.emplace(0, s);
    while (q.size()) {
        Weight d;
        int v;
        tie(d, v) = q.top();
        q.pop();
        d *= -1;
        /* if(v == t) return d; */
        if (dist[v] < d) continue;
        for (auto &e : g[v]) {
            if (dist[e.dst] > dist[v] + e.weight) {
                dist[e.dst] = dist[v] + e.weight;
                q.emplace(-dist[e.dst], e.dst);
            }
        }
    }
    return dist;
}

int main(void) {
    int k;
    cin >> k;
    Graph g(k);
    repeat(i, k - 1) {
        add_arc(g, i, i + 1, 1);
    }
    add_edge(g, k - 1, 0, 1);
    repeat(i, k) {
        int j = (i * 10) % k;
        if (i != j) add_arc(g, i, j, 0);
    }
    auto res = dijkstra(g, 1);
    cout << res[0] + 1 << endl;
}