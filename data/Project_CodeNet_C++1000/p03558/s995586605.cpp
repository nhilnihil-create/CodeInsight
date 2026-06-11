#include <iostream>
#include <vector>
#include <queue>
using namespace std;
constexpr long long INF = 1LL << 62;
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}

struct Edge {
    int src, dst, cost;
    Edge(int s, int d, int c = 1) : src(s), dst(d), cost(c) {}
    bool operator<(const Edge &e){ return cost < e.cost;}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

int main() {
    int k; cin >> k;

    Graph g(k);
    for(int i=0; i < k; ++i) {
        g[i].emplace_back(i, (i * 10) % k, 0);
        g[i].emplace_back(i, (i + 1) % k, 1);
    }

    vector<long long> dist(k, INF);
    deque<int> dq;
    dq.push_front(1);
    dist[1] = 1;

    while(!dq.empty()) {
        int v = dq.front(); dq.pop_front();

        for(Edge e : g[v]) {
            if(chmin(dist[e.dst], dist[e.src] + e.cost)) {
                if(e.cost == 0) dq.push_front(e.dst);
                else dq.push_back(e.dst);
            }
        }
    }
    
    cout << dist[0] << '\n';
    return 0;
}