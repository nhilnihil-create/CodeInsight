#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    set<array<ll, 3>> pieces;

    vll ds(N);
    for (int i = 0; i < N; i++) {
        cin >> ds[i];
        pieces.insert({ ds[i], 1, i });
    }

    vector<pair<int, int>> edges;
    while (pieces.size() > 1) {
        auto p = *pieces.rbegin();
        pieces.erase(p);

        ll match = p[0] + 2 * p[1] - N;
        auto qi = pieces.lower_bound({ match, -1, -1 });
        if (qi == pieces.end() || (*qi)[0] != match) {
            cout << -1 << endl;
            return 0;
        }
        auto q = *qi;

        edges.emplace_back(p[2], q[2]);
        array<ll, 3> comb = { q[0], p[1] + q[1], q[2] };

        pieces.erase(q);
        pieces.insert(comb);
    }

    vvi adj(N);
    for (auto p : edges) {
        adj[p.first].push_back(p.second);
        adj[p.second].push_back(p.first);
    }

    vi dist(N, -1);
    dist[0] = 0;
    for (queue<int> bfs({0}); !bfs.empty(); bfs.pop()) {
        for (int nbr : adj[bfs.front()]) if (dist[nbr] == -1) {
            dist[nbr] = dist[bfs.front()] + 1;
            bfs.push(nbr);
        }
    }

    ll tot0 = 0;
    for (int v : dist)
        tot0 += v;

    if (tot0 != ds[0]) {
        cout << -1 << "\n";
    } else for (auto p : edges) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

    return 0;
}

