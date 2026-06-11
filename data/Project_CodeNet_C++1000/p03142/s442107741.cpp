#include <bits/stdc++.h>
using namespace std;

bool tsort(vector<int> &S, const vector<vector<int>> &edges) {
    int V = edges.size();

    vector<int> indeg(V, 0);
    for(int i = 0; i < V; ++i) {
        for(int to : edges[i]) ++indeg[to];
    }

    stack<int> done;
    for(int i = 0; i < V; ++i) {
        if(indeg[i] == 0) done.push(i);
    }

    while(!done.empty()) {
        int cur = done.top();
        done.pop();
        S.push_back(cur);
        for(int to : edges[cur]) {
            --indeg[to];
            if(indeg[to] == 0) done.push(to);
        }
    }

    return S.size() == V;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edges(N);
    for(int i=0; i<N-1+M; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      edges[a].push_back(b);
    }

    vector<int> order;
    tsort(order, edges);

    vector<int> par(N);
    vector<int> depth(N);
    par[order[0]] = -1;
    depth[order[0]] = 0;
    for(int i=0; i<N; ++i) {
        int cur = order[i];
        for(int to : edges[cur]) {
            if(depth[to] < depth[cur] + 1) {
                par[to] = cur;
            }
            depth[to] = depth[cur] + 1;
        }
    }

    for(int i=0; i<N; ++i) {
        cout << par[i] + 1 << endl;
    }
}