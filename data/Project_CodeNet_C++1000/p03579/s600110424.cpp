#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, M;
    int a, b;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for ( int i = 0; i < M; i++ ) {
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> cs(N,-1);
    function<bool(int,int,int)> dfs = [&](int v, int p, int c) {
        if ( cs[v] != -1 ) {
            if ( cs[v] != c ) return false;
            else  return true;
        }
        cs[v] = c;
        for ( int u : G[v] ) {
            if ( u == p ) continue;
            if ( !dfs(u, v, 1-c) ) return false;
        }
        return true;
    };
    bool bi = dfs(0,-1,0);
    ll n1 = 0, n2 = 0;
    if ( bi ) {
        for ( int i = 0; i < N; i++ ) {
            if ( cs[i] == 0 ) n1++;
        }
    }
    n2 = N - n1;
    ll en;
    if ( bi ) en = n1 * n2;
    else en = n1 * (n1-1) / 2 + n2 * (n2-1) / 2;
    ll ans = en - M;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}