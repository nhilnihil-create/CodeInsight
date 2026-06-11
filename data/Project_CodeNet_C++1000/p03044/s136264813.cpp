#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using Graph = vector<vector<pair<int,int>>>;//次の位置、距離


signed main() {
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        G.at(u).push_back({v,w});
        G.at(v).push_back({u,w});
    }
    vector<int> dist(N,-1);
    dist.at(0) = 0;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int current_pos = que.front();
        que.pop();
        for (int i = 0; i < G.at(current_pos).size(); i++) {
            if (dist.at(G.at(current_pos).at(i).first) != -1) continue;
            dist.at(G.at(current_pos).at(i).first) = dist.at(current_pos) + G.at(current_pos).at(i).second;
            que.push(G.at(current_pos).at(i).first);
        }
    }
    for (int i = 0; i < N; i++) {
        cout << (dist.at(i) % 2) << endl;
    }
}