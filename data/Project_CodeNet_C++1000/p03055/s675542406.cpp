#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve() {
    ll N;
    cin >> N;
    vector<vector<int>> G(N);
    ll a, b;
    for ( int i = 0; i < N-1; i++ ) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int l = -1, dm = -1;
    vector<int> d(N,-1);
    queue<int> q;
    q.push(0);
    d[0] = 0;
    while ( !q.empty() ) {
        int v = q.front();
        q.pop();
        for ( int u : G[v] ) {
            if ( d[u] >= 0 ) continue;
            d[u] = d[v] + 1;
            q.push(u);
            if ( dm < d[u] )  {
                dm = d[u];
                l = u;
            }
        }
    }
    
    int st = l;
    l = -1, dm = -1;
    d.assign(N, -1);
    q.push(st);
    d[st] = 0;
    while ( !q.empty() ) {
        int v = q.front();
        q.pop();
        for ( int u : G[v] ) {
            if ( d[u] >= 0 ) continue;
            d[u] = d[v] + 1;
            q.push(u);
            if ( dm < d[u] )  {
                dm = d[u];
                l = u;
            }
        }
    }
    int di = dm + 1;
    string ans = di % 3 == 2 ? "Second" : "First";
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}