#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
    vector<int> edges;
    int edge_count[2] = {0, 0};
    bool valid = true;
    char label;

    bool IsDeadEnd() const
    {
        return (edge_count[0] < 1 || edge_count[1] < 1);
    }
};

using Graph = vector<Node>;

void AddEdge(Graph &g, int x, int y)
{
    g[x].edges.push_back(y);
    g[x].edge_count[g[y].label - 'A'] += 1;

    g[y].edges.push_back(x);
    g[y].edge_count[g[x].label - 'A'] += 1;
}

void RemoveDeadEnds(Graph &g)
{
    queue<int> q;
    for (size_t i = 0; i < g.size(); i += 1) {
        if (g[i].IsDeadEnd()) {
            g[i].valid = false;
            q.push(i);
        }
    }

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        auto label_index = g[node].label - 'A';
        for (const auto &next : g[node].edges) {
            if (!g[next].valid) {
                continue;
            }
            g[next].edge_count[label_index] -= 1;
            if (g[next].IsDeadEnd()) {
                g[next].valid = false;
                q.push(next);
            }
        }
    }
}

int CompSize(const Graph &g, int node, vector<bool> &visited)
{
    auto size = 1;
    visited[node] = true;

    for (const auto &next : g[node].edges) {
        if (g[next].valid && !visited[next]) {
            size += CompSize(g, next, visited);
        }
    }
    return size;
}

int MaxCompSize(const Graph &g)
{
    vector<bool> visited(g.size(), false);
    auto res = 0;

    for (size_t i = 0; i < g.size(); i += 1) {
        if (g[i].valid && !visited[i]) {
            res = max(res, CompSize(g, i, visited));
        }
    }
    return res;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    cin.get();

    Graph graph(nodes);
    for (auto &node : graph) {
        cin >> node.label;
    }

    for (auto i = 0; i < edges; i += 1) {
        int x, y;
        cin >> x >> y;
        AddEdge(graph, x - 1, y - 1);
    }

    RemoveDeadEnds(graph);
    cout << (MaxCompSize(graph) > 1 ? "Yes" : "No") << "\n";

    return 0;
}
