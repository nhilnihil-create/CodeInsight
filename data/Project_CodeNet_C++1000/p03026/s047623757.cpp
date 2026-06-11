#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<pair<ll, ll>> ab(n - 1);
    vector<vector<ll>> g(n);
    ll mv = -1, mi;
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        ab[i] = make_pair(a, b);
        if (sz(g[a]) > mv) {
            mv = sz(g[a]);
            mi = a;
        }
        if (sz(g[b]) > mv) {
            mv = sz(g[b]);
            mi = b;
        }
    }
    priority_queue<ll> pq;
    rep(i, n) {
        ll c;
        cin >> c;
        pq.push(c);
    }
    queue<ll> q;
    q.push(mi);
    vector<ll> ans(n, -1);
    ans[mi] = pq.top(); pq.pop();
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        for(auto u : g[p]) {
            if (ans[u] != -1) continue;
            ans[u] = pq.top(); pq.pop();
            q.push(u);
        }
    }
    ll tot = 0;
    rep(i, n - 1) {
        tot += min(ans[ab[i].first], ans[ab[i].second]);
    }
    printf("%lld\n", tot);
    rep(i, n) printf("%lld%s", ans[i], (i == (n - 1)) ? "\n" : " ");
    return 0;
}
