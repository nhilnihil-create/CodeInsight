#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
using P = pair<ll,int>;
const ll INF = 1ll<<60;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<P>> G(n);
    for (int i = 0; i < m; i++) {
        int r, l; ll d;
        cin >> r >> l >> d;
        r--; l--;
        G[l].push_back(P(d,r));
        G[r].push_back(P(-d,l));
    }

    vector<ll> dist(n,INF);
    for (int i = 0; i < n; i++) {
        if (dist[i] != INF) continue;
        dist[i] = 0;
        queue<int> que;
        que.push(i);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            ll d = dist[v];
            for (auto nv : G[v]) {
                if (dist[nv.second] == INF) {
                    dist[nv.second] = dist[v] + nv.first;
                    que.push(nv.second);
                } 
                else if (dist[nv.second] != dist[v] + nv.first) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}