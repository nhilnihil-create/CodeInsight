#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

typedef pair<ll, ll> P;
struct edge { ll to, cost; };

const int MAX_V = 300000;
const ll INF = 1LL<<60;

int V;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(ll s) {
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        rep(i,G[v].size()) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    cin >> V;
    int a, b;
    rep(i, V - 1) {
        cin >> a >> b;
        G[a - 1].push_back({b - 1, 1});
        G[b - 1].push_back({a - 1, 1});
    }
    dijkstra(0);
    int dmax = 0;
    a = 0;
    rep(i, V) {
        if (d[i] > dmax) {
            dmax = d[i];
            a = i;
        }
    }
    dijkstra(a);
    dmax = 0;
    rep(i, V) {
        if (d[i] > dmax) {
            dmax = d[i];
        }
    }
    if (dmax % 3 == 1) cout << "Second\n";
    else cout << "First\n";
}
