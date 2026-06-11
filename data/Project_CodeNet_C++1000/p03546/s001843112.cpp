#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

const int INF = 1e5;
vector<int> dist(10, INF);

struct edge
{
    int to;
    int cost;
};

void dijkstra(const vector<vector<edge>> &G, int s)
{
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.push(P(0, s));

    while (!que.empty())
    {
        P p1 = que.top();
        que.pop();
        int v = p1.second;
        if (dist[v] < p1.first)
            continue;

        for (auto e : G[v])
        {
            if (dist[e.to] > dist[v] + e.cost)
            {
                dist[e.to] = dist[v] + e.cost;
                que.push(P(dist[e.to], e.to));
            }
        }
    }
}

int main() {
    int H,W; cin >> H >> W;
    vector<vector<edge>> G(10, vector<edge>());
    REP(i,10) REP(j,10) {
        int c; cin >> c;
        if(i == j) continue;
        edge e = {j, c};
        G[i].push_back(e);
    }
    veci cost(10); // i -> 1に変える最小値
    REP(i,10) {
        if(i == 1) cost[i] = 0;
        else {
            dist.assign(10,INF);
            dijkstra(G,i);
            cost[i] = dist[1];
        }
    }
    ll ans = 0;
    REP(i,H) REP(j,W) {
        int a; cin >> a;
        if(a == -1 || a == 1) continue;
        ans += cost[a];
    }
    cout << ans << endl;
}
