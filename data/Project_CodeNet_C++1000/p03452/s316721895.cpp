#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
    vector<pair<int, int64_t>> edges;
    int64_t pos = 0;
    bool is_set = false;
};

using Graph = vector<Node>;

bool Bfs(Graph &g, int start)
{
    if (!g[start].is_set) {
        g[start].pos = 0;
        g[start].is_set = true;
    }

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        for (const auto &edge : g[node].edges) {
            if (g[edge.first].is_set) {
                if (g[edge.first].pos != g[node].pos + edge.second) {
                    return false;
                }
                continue;
            }

            g[edge.first].pos = g[node].pos + edge.second;
            g[edge.first].is_set = true;
            q.push(edge.first);
        }
    }
    return true;
}

bool Solve(Graph &g)
{
    for (size_t i = 0; i < g.size(); i += 1) {
        if (!g[i].is_set && !Bfs(g, i)) {
            return false;
        }
    }
    return true;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    Graph graph(nodes);
    for (auto i = 0; i < edges; i += 1) {
        int a, b, dist;
        cin >> a >> b >> dist;

        graph[a - 1].edges.push_back({b - 1, dist});
        graph[b - 1].edges.push_back({a - 1, -dist});
    }

    cout << (Solve(graph) ? "Yes" : "No") << "\n";
    return 0;
}
