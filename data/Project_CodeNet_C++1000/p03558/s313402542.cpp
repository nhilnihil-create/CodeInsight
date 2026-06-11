#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge
{
    int node;
    int cost;

    bool operator<(const Edge &other) const
    {
        return cost > other.cost;
    }
};

using Graph = vector<vector<Edge>>;

Graph BuildGraph(int num)
{
    Graph graph(num);
    for (int i = 0; i < num; i += 1) {
        graph[i].push_back({(i + 1) % num, 1});
        graph[i].push_back({(i * 10) % num, 0});
    }
    return graph;
}

int MinDist(const Graph &g, int start, int stop)
{
    vector<int> dist(g.size(), (1 << 30));
    dist[start] = 0;

    priority_queue<Edge> heap;
    heap.push({start, 0});

    while (!heap.empty()) {
        int node = heap.top().node;
        int cost = heap.top().cost;
        heap.pop();

        if (cost > dist[node]) {
            continue;
        }
        if (node == stop) {
            break;
        }

        for (const auto &e : g[node]) {
            if (dist[node] + e.cost < dist[e.node]) {
                dist[e.node] = dist[node] + e.cost;
                heap.push({e.node, dist[e.node]});
            }
        }
    }
    return dist[stop];
}

int Solve(int num)
{
    auto graph = BuildGraph(num);
    return MinDist(graph, 1, 0) + 1;
}

int main()
{
    int num;
    cin >> num;

    int res = Solve(num);
    cout << res << "\n";

    return 0;
}
