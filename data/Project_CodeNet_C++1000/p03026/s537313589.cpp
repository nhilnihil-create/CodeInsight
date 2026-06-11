#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<pair<int, int>> edges;
    int mc = 0, mv = -1;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        edges.emplace_back(a, b);
        if (mc < sz(g[a])) {
            mc = sz(g[a]);
            mv = a;
        }
        if (mc < sz(g[b])) {
            mc = sz(g[b]);
            mv = b;
        }
    }
    priority_queue<int> pq;
    rep(i, n) {
        int c;
        cin >> c;
        pq.push(c);
    }
    vector<int> d(n, -1);
    d[mv] = pq.top(); pq.pop();
    queue<int> q;
    q.push(mv);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (auto x : g[u]) {
            if (d[x] != -1) continue;
            d[x] = pq.top();
            pq.pop();
            q.push(x);
        }
    }
    ll total = 0;
    rep(i, n - 1) {
        total += min(d[edges[i].first], d[edges[i].second]);
    }
    printf("%lld\n", total);
    rep(i, n) {
        printf("%d%s", d[i], (i == (n - 1)) ? "\n" : " ");
    }
    return 0;
}
