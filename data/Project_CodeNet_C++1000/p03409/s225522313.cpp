#include <bits/stdc++.h>

//#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

typedef pair<int, int> P;

#define rep(i, a, b) for(int i=a;i<b;i++)
#define fore(i, a) for(auto &i:a)
typedef long long ll;
const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;

struct BipartiteMatching {
    vector<vector<int>> E;
    int n, m;
    vector<int> match, dist;

    void init(int _n, int _m) {
        n = _n, m = _m;
        E.resize(n + m + 2);
        match.resize(n + m + 2);
        dist.resize(n + m + 2);
    }

    bool bfs() {
        queue<int> que;
        rep(i, 1, n + 1) {
            if (!match[i]) dist[i] = 0, que.push(i);
            else dist[i] = inf;
        }
        dist[0] = inf;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            if (u)
                fore(v, E[u]) if (dist[match[v]] == inf) {
                        dist[match[v]] = dist[u] + 1;
                        que.push(match[v]);
                    }
        }
        return (dist[0] != inf);
    }

    bool dfs(int u) {
        if (u) {
            fore(v, E[u]) if (dist[match[v]] == dist[u] + 1)
                    if (dfs(match[v])) {
                        match[v] = u;
                        match[u] = v;
                        return true;
                    }
            dist[u] = inf;
            return false;
        }
        return true;
    }

    void add(int a, int b) {
        b += n;
        E[a + 1].push_back(b + 1);
        E[b + 1].push_back(a + 1);
    }

    int whois(int x) { return match[x + 1] - 1; }

    int solve() {
        rep(i, 0, n + m + 1) match[i] = 0;
        int res = 0;
        while (bfs()) rep(i, 1, n + 1) if (!match[i] && dfs(i)) res++;
        return res;
    }
};

int main() {
    int N;
    cin >> N;
    vector<P> R(N);
    vector<P> B(N);
    rep(i, 0, N) cin >> R[i].first >> R[i].second;
    rep(i, 0, N) cin >> B[i].first >> B[i].second;

    BipartiteMatching bm;
    bm.init(N, N);
    rep(i, 0, N) rep(j, 0, N) {
            if (R[i].first < B[j].first && R[i].second < B[j].second) bm.add(i, j);
        }
    cout << bm.solve() << endl;
}
