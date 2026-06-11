#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<vector<int>> G, vector<int> indeg, int root, int N) {
    vector<int> par(N, -1);
    vector<int> dist(N, -1);
    dist[root] = 0;

    queue<int> Q;
    Q.push(root);

    while(!Q.empty()) {
        int v = Q.front(); Q.pop();
        for(int to : G[v]) {
            if(dist[to] < dist[v] + 1) {
                dist[to] = dist[v] + 1;
                par[to] = v;
            }
            indeg[to] -= 1;
            if(indeg[to] == 0) Q.push(to);
        }
    }

    return par;
}

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> indeg(N, 0);
    for(int i=0; i<N-1+M; ++i) {
        int x, y; cin >> x >> y;
        G[x - 1].push_back(y - 1);
        indeg[y - 1] += 1;
    }

    int root = -1;
    for(int i=0; i<N; ++i) {
        if(indeg[i] == 0) {
            root = i;
            break;
        }
    }

    auto par = solve(G, indeg, root, N);
    for(int i=0; i<N; ++i) cout << par[i] + 1 << endl;
}