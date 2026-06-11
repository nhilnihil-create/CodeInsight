/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2020
 */
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

void dfs(int node, int parent, int path, 
        const vector<vector<pair<int, int>>> & tree, vector<int> * colors) {
    if(path % 2) (*colors)[node] = 1;
    for(auto &  p : tree[node]) {
        int v = p.first, w = p.second;
        if(v != parent) dfs(v, node, path + w, tree, colors);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> tree(n);
    for(int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }
    vector<int> colors(n, 0);
    dfs(0, -1, 0, tree, &colors);
    for(int color : colors) cout << color << "\n";
    // need to know distance of two nodes
    return 0;
}

