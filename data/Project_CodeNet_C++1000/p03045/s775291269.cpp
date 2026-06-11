#include <cstdio>
#include <vector>
#include <set>

using namespace std;

void dfs(vector<set<int>>& adj, vector<bool>& visited, int here) {
    visited[here] = true;
    for(int there : adj[here]) {
        if(!visited[there]) dfs(adj, visited, there);
    }
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<set<int>> adj(n, set<int>()); // adj[x]: x와 연결된 정점들
    for(int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        adj[x-1].insert(y-1);
        adj[y-1].insert(x-1);
    }
    vector<bool> visited(n);

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            cnt++;
            dfs(adj, visited, i);
        }
    }
    printf("%d",cnt);

    return 0;
}
