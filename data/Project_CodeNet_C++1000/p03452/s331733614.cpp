#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <stack>

using namespace std;

using ll = long long;
using p = pair<ll, ll>;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr ll MAX_N = 100000 + 1;

vector<p> G[MAX_N + 1];
ll Nodes[MAX_N + 1];

bool dfs(ll node) {
    bool ret = true;
    for (auto g : G[node]) {
        ll n = g.first;
        ll w = g.second;
        if (Nodes[n] == INF) {
            Nodes[n] = Nodes[node] + w;
            ret &= dfs(n);
        } else if (Nodes[n] != Nodes[node] + w) {
            return false;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;

    fill(Nodes + 1, Nodes + N + 1, INF);

    for (ll i = 0; i < M; i++) {
        ll l, r, d;
        cin >> l >> r >> d;
        G[l].push_back(p(r,  d));
        G[r].push_back(p(l, -d));
    }

    for (ll i = 1; i <= N; i++) {
        if (Nodes[i] == INF) {
            Nodes[i] = 0;
            if (!dfs(i)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}

