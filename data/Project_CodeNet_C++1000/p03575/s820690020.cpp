#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<vector<ll> > Graph;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


vector<bool> seen;
void dfs(const Graph &G, ll v, P rm) {
    seen[v] = true;

    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        if (rm==make_pair(min(v, next_v), max(v, next_v))) continue;
        dfs(G, next_v, rm);
    }
}


int main() {
    ll N, M; cin >> N >> M;

    Graph G(N);
    vector<P> r;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        r.push_back(make_pair(min(a, b), max(a, b)));
    }
    ll ans = 0;
    for (ll i = 0; i < M; ++i) {
        seen.assign(N, false);
        dfs(G, 0, r[i]);
        bool check = true;
        for (ll j = 0; j < N; ++j) if (!seen[j]) check = false;
        if (!check) ans++;
    }
    cout << ans << endl;
}