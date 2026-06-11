#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
constexpr long long INF = 1LL << 62;

struct Edge {
    int src, dst, cost;
    Edge(int s, int d, int c = 1) : src(s), dst(d), cost(c) {}
    bool operator<(const Edge &e){ return cost < e.cost;}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

// O(|V|+|E|)log|V|)
void dijkstra(int s, Graph &g, vector<long long> &dist) {
    using Info = pair<long long, int>;
    // init
    dist.assign(g.size(), INF);
    dist[s] = 0;
    priority_queue<Info, vector<Info>, greater<Info> > pq;
    pq.emplace(0, s);
    
    // main
    while(!pq.empty()){
        long long d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(dist[v] < d) continue;
        for(Edge e : g[v]){
            if(dist[e.dst] > dist[v] + e.cost){
                dist[e.dst] = dist[v] + e.cost;
                pq.emplace(dist[e.dst], e.dst);
            }
        }
    }

}

int main() {
    int k; cin >> k;

    // build a graph
    Graph g(k+1);
    for(int i = 1; i < k; ++i) {
        g[i].emplace_back(i, (i+1) %k, 1);
        g[i].emplace_back(i, (i*10)%k, 0);
    }

    // calc
    vector<long long> dist;
    dijkstra(1, g, dist);

    // out
    cout << dist[0] + 1 << '\n';
    return 0;
}