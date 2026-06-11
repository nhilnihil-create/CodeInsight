#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    ll a, b;
    vector<int> deg_in(N), topo, dep(N);
    for ( int i = 0; i < N-1+M; i++ ) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        deg_in[b]++;
    }
    queue<int> q;
    for ( int i = 0; i < N; i++ ) {
        if ( deg_in[i] == 0 ) {
            q.push(i);
            dep[i] = 0;
        }
    }
    while ( !q.empty() ) {
        int v = q.front();
        q.pop();
        topo.push_back(v);
        for ( int u : G[v] ) {
            deg_in[u]--;
            if ( deg_in[u] == 0 ) q.push(u);
            dep[u] = max(dep[u], dep[v]+1);
        }
    }

    vector<int> ans(N, -1);
    queue<int> q2;
    q2.push(topo[0]);
    while ( !q2.empty() ) {
        int v = q2.front();
        q2.pop();
        for ( int u : G[v] ) {
            if ( dep[u] - dep[v] == 1 ) {
                ans[u] = v;
                q2.push(u);
            }
        }
    }

    for ( int i = 0; i < N; i++ ) {
        cout << ans[i] + 1 << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}