#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;

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

    void bfs(int s) {
        for(auto& e : nodes) e.dist = INF, e.par = -1;
        queue<int> que;
        nodes[s].dist = 0;
        que.push(s);

        while(!que.empty()) {
            int index = que.front(); que.pop();
            for(auto& e : nodes[index].edge) {
                if(nodes[e.to].dist != INF)  continue;
                nodes[e.to].dist = nodes[index].dist + 1;
                nodes[e.to].par = index;
                que.push(e.to);
            }
        }
    }

    lint shortest_dist(int to) { return nodes[to].dist; }
};

int main() {
    lint n;
    cin >> n;

    Graph g(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        g.add_edge(a-1, b-1, 1);
        g.add_edge(b-1, a-1, 1);
    }

    g.bfs(0);
    pair<lint, lint> mx;
    for(int i=0; i<n; i++) {
        mx = max(mx, P(g.shortest_dist(i), i));
    }

    g.bfs(mx.second);
    lint diameter = -1e18;
    for(int i=0; i<n; i++) {
        diameter = max(diameter, g.shortest_dist(i));
    }

    // bool: first == winner
    static vector<bool> dp(n);
    dp[0] = true;
    dp[1] = false;
    for(int i=2; i<n; i++) {
        dp[i] = not(dp[i-1]&dp[i-2]);
    }
    cout << (dp[diameter] ? "First" : "Second") << endl;
}