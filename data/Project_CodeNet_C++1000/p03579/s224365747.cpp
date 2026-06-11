#include<bits/stdc++.h>

using namespace std;

using ll = long long;
#define long long long

int main(void) {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> G(n);
    for(ll i=0; i<m; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ll r = 0;

    bool eo = false;
    ll e = 0, o = 0;

    vector<ll> t(n);
    auto dfs = [&](auto dfs, ll cur, ll pre, ll d) -> ll {
        if(t[cur]) return t[cur];
        t[cur] = d;
        (d&1 ? o : e)++;

        for(auto &v: G[cur]) {
            if(v == pre) continue;

            ll dd = dfs(dfs, v, cur, d+1);
            if(~(d+dd)&1) eo = true;
        }
        return t[cur];
    };

    dfs(dfs, 0, -1, 1);

    cout << (eo ? n*(n-1)/2 - m : e*o - m) << endl;
}
