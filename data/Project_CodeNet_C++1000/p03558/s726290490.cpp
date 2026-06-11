#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <map>
#include <stack>
#include <map>
#include <unordered_map>
#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define REPI(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;
using P = pair<long, long>;
using VI = vector<long>;


class Graph {
    int n;
    vector<vector<pair<int, double>>> adj;
    vector<double> d;
    
public:
    Graph(int n) {
        this->n = n;
        adj = vector<vector<pair<int, double>>>(n, vector<pair<int, double>>());
    }
    void addArc(int a, int b, double w) {
        adj[a].push_back(make_pair(b, w));
    }
    
    void addEdge(int a, int b, double w) {
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }
    
    void dijkstra(int a) {
        d = vector<double>(n, INF);
        d[a] = 0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
        q.push(make_pair(0, a));
        
        while (!q.empty()) {
            int u = q.top().second;
            q.pop();
            
            for (auto i: adj[u]) {
                if (d[i.first] > d[u] + i.second) {
                    d[i.first] = d[u] + i.second;
                    q.push(make_pair(d[i.first], i.first));
                }
            }
        }
    }
    
    double dist(int a) {
        return d[a];
    }
};

bool hoge(int k) {
    while (k % 2 == 0) {
        k /= 2;
    }
    while (k % 5 == 0) {
        k /= 5;
    }
    return k == 1;
}

int main() {
    int k;
    cin >> k;
    if (hoge(k)) {
        cout << 1 << endl;
        return 0;
    }
    
    Graph g(k);
    long l = 1;
    for (int i = 1; i < k; i++) {
        g.addArc(i, (i + 1) % k, 1);
        g.addArc(i, (i * 10) % k, 0);
    }
    g.dijkstra(1);
    cout << int(g.dist(0)) + 1 << endl;
}
