#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct Graph
{
    vector<tuple<int, int, int>> edges;
    int nodes;

    Graph(int nodes) : nodes(nodes) {}

    void AddEdge(int a, int b, int cost)
    {
        edges.push_back(make_tuple(a, b, cost));
    }
};

int Log2(int num)
{
    return log(num) / log(2);
}

void Print(const Graph &g)
{
    cout << g.nodes << " " << g.edges.size() << "\n";
    for (const auto &e : g.edges) {
        int a, b, cost;
        tie(a, b, cost) = e;
        cout << a + 1 << " " << b + 1 << " " << cost << "\n";
    }
}

int main()
{
    int paths;
    cin >> paths;

    Graph graph(Log2(paths) + 1);
    for (int i = 0; i + 1 < graph.nodes; i += 1) {
        graph.AddEdge(i, i + 1, 0);
        graph.AddEdge(i, i + 1, (1 << i));
    }

    int next_cost = (1 << (graph.nodes - 1));
    paths -= next_cost;

    while (paths > 0) {
        int l = Log2(paths);
        graph.AddEdge(l, graph.nodes - 1, next_cost);
        paths -= (1 << l);
        next_cost += (1 << l);
    }

    Print(graph);
    return 0;
}
