#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

struct Graph {
    struct VertexQ {
        bool operator<(const VertexQ& o) const {
            return c > o.c; // 逆
        }
        int i;
        int64_t c;
    };
    struct Vertex { int n; int64_t c; };
    struct Edge { int i, n, c; };
    Graph(int n, int m) : v(n, { -1 }), e(m), n(n), m(0) {}
    void add_edge(int i, int j, int c) {
        e[m] = { j, v[i].n, c };
        v[i].n = m;
        m++;
    }
    void dijkstra(int i, int j) {
        for (int i = 0; i < n; i++) v[i].c = (int64_t)1 << 60;
        priority_queue<VertexQ> q;
        q.push({ i, v[i].c = 0 });
        while (!q.empty()) {
            auto p = q.top(); q.pop();
            if (p.i == j) break;
            if (p.c > v[p.i].c) continue;
            for (int j = v[p.i].n; j >= 0; j = e[j].n) {
                Edge& o = e[j];
                int64_t c = p.c + o.c;
                if (c < v[o.i].c) q.push({ o.i, v[o.i].c = c });
            }
        }
    }
    vector<Vertex> v;
    vector<Edge> e;
    int n, m;
};

int main() {
    int k;
    cin >> k;

    Graph g(k, (k - 1) * 2);
    for (int i = 1; i < k; i++) {
        g.add_edge(i, i * 10 % k, 0);
        g.add_edge(i, (i + 1) % k, 1);
    }

    g.dijkstra(1, 0);

    cout << g.v[0].c + 1 << endl;

    return 0;
}