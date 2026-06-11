#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

struct Graph {
    struct Edge { int from; int to; lint cost; };
    struct Node {
        Node() : par(-1), done(false), dist(INF) {}
        int index;
        int par;
        bool done;
        lint dist;
        vector<Edge> edge;
    };

    int n;
    vector<Node> nodes;
    vector<Edge> edges;
    const static lint INF = 1e18;

    Graph(int n) : n(n) {
        nodes.resize(n);
        for(int i=0; i<n; i++)  nodes[i].index = i;
    }

    void add_edge(int from, int to, lint cost) {
        nodes[from].edge.push_back(Edge{from, to, cost});
        edges.push_back(Edge{from, to, cost});
    }
};

int main() {
    lint L;
    cin >> L;

    Graph g(21);
    lint k, last;
    for(k=last=1;; k*=2,last++) {
        if(L > k) {
            g.add_edge(last, last+1, 0);
            g.add_edge(last, last+1, k);
            L -= k;
        } else {
            break;
        }
    }

    bitset<100> bs(L-1);
    for(int i=0; i<100; i++) {
        if(bs[i]) {
            g.add_edge(i+1,last, k);
            k += pow(2, i);
        }
    }

    int N = 0;
    for(auto e : g.edges) {
        N = max(N, e.to);
    }

    cout << N << " " << g.edges.size() << endl;
    for(auto e : g.edges) {
        cout << e.from << " " << e.to << " " << e.cost << endl;
    }
}