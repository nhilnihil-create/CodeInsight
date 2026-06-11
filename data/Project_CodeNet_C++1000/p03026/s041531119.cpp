#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    constexpr double PI = acos(-1);
    cout << fixed << setprecision(16);
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<vector<ll>> G(n);
    for(ll i=0; i<n-1; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> c(n);
    for(auto &e: c) cin >> e;
    sort(c.begin(), c.end(), greater<>());

    vector<ll> res(n);
    {
        auto it = c.begin();

        ll s = accumulate(c.begin()+1, c.end(), 0);
        auto dfs = [&](auto dfs, ll cur, ll pre) -> void{
            res[cur] = *it++;
            for(auto &e: G[cur]) {
                if(e == pre) continue;
                dfs(dfs, e, cur);
            }
        };
        dfs(dfs, 0, -1);

        cout << s << endl;
        for(auto &e: res) cout << e << ' '; cout << endl;
    }
}
