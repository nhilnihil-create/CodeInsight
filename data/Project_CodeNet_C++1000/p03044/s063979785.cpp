#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<int, vector<pair<int, int>>> uv;
    // map<int, vector<pair<int, int>>> vu; // 区別する必要がなかった

    int E = N - 1;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;
        u--;
        v--;
        w = (w % 2 == 0) ? 2 : 1;
        uv[u].push_back(pair<int, int>(v, w));
        uv[v].push_back(pair<int, int>(u, w));
        // vu[v].push_back(pair<int, int>(u, w));
    }

    vector<int> colors(N);
    for (int i = 0; i < N; i++) {
        colors[i] = -1;
    }
    colors[0] = 1;

    stack<int> nodeids;
    nodeids.push(0);
    while (!nodeids.empty()) {
        int nod = nodeids.top();
        nodeids.pop();
        for (auto e : uv[nod]) {
            int v = e.first;
            int w = e.second;
            if (colors[v] == -1) {
                if (w == 2) {
                    colors[v] = colors[nod];
                } else {
                    colors[v] = 1 - colors[nod];
                }
                nodeids.push(v);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << colors[i] << endl;
    }
}
