#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    vector<ll> cnt(n, 0);
    set<ll> on, off;
    rep(i, n - 1 + m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        on.insert(a);
        off.insert(b);
        cnt[b]++;
    }
    ll root = 0;
    rep(i, n) {
        if ((on.count(i) > 0) && (off.count(i) == 0)) {
            root = i;
            break;
        }
    }
    vector<ll> ans(n);
    ans[root] = -1;
    queue<ll> q;
    q.push(root);
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for(auto v : g[u]) {
            if (cnt[v] == 1) {
                ans[v] = u;
                q.push(v);
            }
            else {
                cnt[v]--;
            }
        }
    }
    rep(i, n) {
        cout << (ans[i] + 1) << endl;
    }
    return 0;
}
