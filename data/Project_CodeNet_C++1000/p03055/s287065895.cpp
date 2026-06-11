#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Node {
    bool done;
    int dist;
    vector<int> to;
};

int dfs(int pos, vector<Node>& node) {
    node[pos].done = true;
    int res = node[pos].dist;
    for (int i = 0; i < node[pos].to.size(); i++) {
        int nex = node[pos].to[i];
        if (node[nex].done == false) {
            node[nex].dist = node[pos].dist + 1;
            res = max(res, dfs(nex, node));
        }
    }
    return res;
}

int tree_diameter(vector<Node>& node) {
    int n = node.size();
    for (int i = 0; i < n; i++) {
        node[i].done = false;
        node[i].dist = INF;
    }
    node[0].dist = 0;
    int res = dfs(0, node);
    int pos;
    for (int i = 0; i < n; i++) {
        if (node[i].dist == res) {
            pos = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        node[i].done = false;
        node[i].dist = INF;
    }
    node[pos].dist = 0;
    return dfs(pos, node);
}

int main() {
    int n;
    cin >> n;
    vector<Node> node(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        node[a].to.push_back(b);
        node[b].to.push_back(a);
    }
    
    int d = tree_diameter(node);
    if (d % 3 == 1) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
    return 0;
}