#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

struct Edge {
    int to;
    ll dist;
};

bool solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<Edge>> G(N);
    int l, r;
    ll d;
    for ( int i = 0; i < M; i++ ) {
        cin >> l >> r >> d;
        l--, r--;
        G[l].push_back(Edge{r,d});
        G[r].push_back(Edge{l,-d});
    }

    vector<ll> pos(N, -INF);
    function<bool(int,int,ll)> dfs = [&](int v ,int p, ll x) {
        if ( pos[v] != -INF ) {
            if ( pos[v] != x ) return false;
            else return true;
        }
        pos[v] = x;
        for ( auto e : G[v] ) {
            if ( e.to == p ) continue;
            if ( !dfs(e.to, v, x + e.dist) ) return false;
        }
        return true;
    };
    
    for ( int i = 0; i < N; i++ ) {
        if ( pos[i] != -INF ) continue;
        if ( !dfs(i, -1, 0) ) return false;
    }

    return true;
}

int main() {
    string ans = solve() ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}