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
    string S;
    cin >> S;

    int N = S.length();
    bool c1 = (S[N-1] == '0');
    bool c2 = (S[0] == S[N-2] && S[N-2] == '1');
    bool c3 = true;
    for(int i=0; i<=N-2; i++) c3 &= (S[i] == S[N-i-2]);

    if(not(c1 && c2 && c3)) {
        cout << -1 << endl;
        return 0;
    }

    vector<char> T(S.begin(), S.begin()+N/2);

    Graph g(N);
    int p = 0;
    for(int i=0; i<T.size(); i++) {
        if(T[i] == '1') {
            g.add_edge(p, i+1, 1);
            p = i+1;
        } else {
            g.add_edge(p, i+1, 1);
        }
    }

    for(int i=T.size(); i<S.size()-1; i++) {
        g.add_edge(p, i+1, 1);
    }

    for(auto e : g.edges) {
        cout << e.from+1 << " " << e.to+1 << endl;
    }
}