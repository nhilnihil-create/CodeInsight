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
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<pair<ll, ll>> ab(n - 1);
    vector<vector<ll>> g(n);
    vector<ll> cnt(n, 0);
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        ab[i] = make_pair(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    ll mv = -1, mi = 0;
    rep(i, n) {
        if (mv < cnt[i]) {
            mv = cnt[i];
            mi = i;
        }
    }
    multiset<ll> s;
    rep(i, n) {
        ll c;
        cin >> c;
        s.insert(c);
    }
    auto it = s.end(); it--;
    vector<ll> ans(n, -1);
    queue<ll> q;
    q.push(mi);
    ans[mi] = *it; it--;
    while(!q.empty()) {
        ll v = q.front(); q.pop();
        for(auto x : g[v]) {
            if (ans[x] != -1) continue;
            ans[x] = *it;
            if (it != s.begin()) it--;
            q.push(x);
        }
    }
    ll score = 0;
    rep(i, n - 1) {
        ll a = ab[i].first, b = ab[i].second;
        score += min(ans[a], ans[b]);
    }
    printf("%lld\n", score);
    rep(i, n) printf("%lld%s", ans[i], (i == (n - 1)) ? "\n" : " ");
    return 0;
}
