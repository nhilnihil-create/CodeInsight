#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Node {
    bool done;
    int dist;
    vector<int> to;
};

void diameter(int pos, int& res, vector<Node>& node) {
    node[pos].done = true;
    res = max(res, node[pos].dist);
    for (int i = 0; i < node[pos].to.size(); i++) {
        int npos = node[pos].to[i];
        if (node[npos].done == false) {
            node[npos].dist = node[pos].dist + 1;
            diameter(npos, res, node);
        }
    }
    return;
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

    for (int i = 0; i < n; i++) {
        node[i].done = false;
        node[i].dist = INF;
    }
    node[0].dist = 0;
    int res = 0;
    diameter(0, res, node);
    int pos;
    for (int i = 0; i < n; i++) {
        if (node[i].dist == res) {
            pos = i;
        }
    }
    for (int i = 0; i < n; i++) {
        node[i].done = false;
        node[i].dist = INF;
    }
    node[pos].dist = 0;
    diameter(pos, res, node);
    if (res % 3 == 1) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
    return 0;
}