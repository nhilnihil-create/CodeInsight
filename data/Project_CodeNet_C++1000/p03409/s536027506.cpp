#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

struct Dinic {
    struct Edge {int to, rev, cap;};
    vector<vector<Edge>> Graph;
    vector<int> dist, iter;
    Dinic(int v) : Graph(v) {}
    void AddEdge(int from, int to, int cap) {
        Graph[from].push_back({to, SZ(Graph[to]), cap});
        Graph[to].push_back({from, SZ(Graph[from]) - 1, 0});
    }
    bool bfs(int s, int t) {
        dist.assign(SZ(Graph), -1);
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        while (!q.empty() && dist[t] == -1) {
            int v = q.front();
            q.pop();
            for (const auto &e: Graph[v]) {
                if (e.cap > 0 && dist[e.to] == -1) {
                    dist[e.to] = dist[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return dist[t] != -1;
    }
    int dfs(int now, int t, int mn) {
        if (now == t) return mn;
        for (int &i = iter[now]; i < SZ(Graph[now]); ++i) {
            Edge &e = Graph[now][i];
            if (e.cap > 0 && dist[now] + 1 == dist[e.to]) {
                int d = dfs(e.to, t, min(mn, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    Graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    int MaxFlow(int s, int t) {
        int ans = 0;
        while (bfs(s, t)) {
            iter.assign(SZ(Graph), 0);
            int f = 0;
            while ((f = dfs(s, t, 1001001001)) > 0) ans += f;
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    REP(i, n) cin >> a[i] >> b[i];
    REP(i, n) cin >> c[i] >> d[i];
    Dinic D(2 * n + 2);
    REP(i, n) {
        D.AddEdge(0, i + 1, 1);
        D.AddEdge(i + n + 1, 2 * n + 1, 1);
    }
    REP(i, n) REP(j, n) {
        if (a[i] < c[j] && b[i] < d[j]) {
            D.AddEdge(i + 1, j + n + 1, 1);
        }
    }
    cout << D.MaxFlow(0, 2 * n + 1) << "\n";
    return 0;
}
