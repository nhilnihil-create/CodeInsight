#include <bits/stdc++.h>

using namespace std;
#define ll long long 
const ll maxn = 55;
int n; // number of nodes
vector<int> adj[maxn]; // adjacency list of graph
int bridges=0;
vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridges++;
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(maxn, false);
    tin.assign(maxn, -1);
    low.assign(maxn, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
int main(){
    int m;
   cin >> n >> m;
   int a,b;
   for(int i=0;i<m;i++){
       cin >> a >> b;
       adj[a].push_back(b);
       adj[b].push_back(a);
   }
   find_bridges();
   cout << bridges;
}