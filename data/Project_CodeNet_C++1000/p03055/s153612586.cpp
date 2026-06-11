#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

int main(void) {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    REP(i, n-1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<ll> dist(n, INF);
    auto dfs = [&](auto &&self, ll v, ll p, ll d) -> void {
        dist[v] = d;
        for(auto to: g[v]) if(to != p) {
            self(self, to, v, d+1);
        }
    };
    dfs(dfs, 0, -1, 0);
    ll ma = -1, idx = -1;
    REP(i, n) if(ma < dist[i]) ma = dist[i], idx = i;

    dist.assign(n, INF);
    dfs(dfs, idx, -1, 0);
    ma = 0;
    REP(i, n) chmax(ma, dist[i]);

    if(ma == 0) cout << "First\n";
    else if(ma == 1) cout << "Second\n";
    else {
        ma -= 2;
        ma %= 3;
        if(ma <= 1) cout << "First\n";
        else cout << "Second\n"; 
    } 

    return 0;
}