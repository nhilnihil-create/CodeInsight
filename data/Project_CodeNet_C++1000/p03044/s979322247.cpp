//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <iomanip>  //setprecision(桁)
using namespace std;
#define pb push_back
#define ll long long int
#define rep(i,n) for(int i = 0;i < n;i++)
#define INF 1e+9
const ll MOD = 1000000007;

struct edge {
    int to;
    ll cost;
};

// <最短距離, 頂点の番号>
using P = pair<double, int>;

int V;
const int ci = 2e5+ 5;
vector<edge> G[ci];
double d[ci];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i=0; i<G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

vector<edge> g[100005];
int main() {
    int n; cin >> n;
    rep(i,n-1){
        int u, v; ll w; cin >> u >> v >> w;
        u--; v--;
        edge e1 = {v,w};
        edge e2 = {u,w};
        g[u].push_back(e1);
        g[v].push_back(e2);
    }

    vector<ll> dist(n);
    vector<bool> vis(n,false);
    queue<int> que;
    que.push(0);
    vis[0] = true;

    while(que.size()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < g[v].size(); i++) {
            edge e = g[v][i];
            if(!vis[e.to]){
                vis[e.to] = true;
                dist[e.to] = dist[v] + e.cost; //cout << e.cost << endl;
                que.push(e.to);
            }
        }
    }
    vector<int> color(n);
    for(int i = 0; i < n; i++){
        if(dist[i] % 2 == 0){
            color[i] = 1;
        }else{
            color[i] = 0;
        }
    }
    for(auto i : color) cout << i << endl;
}
