#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()
using namespace std;

vector<pair<int, int>> G[100001];
int dist[100001];
bool used[100001];

bool dfs(int x, int d) {
    if (used[x]) return d == dist[x];

    dist[x] = d;
    used[x] = true;
    for (auto p : G[x]) {
        if (!dfs(p.first, d + p.second))
            return false;
    }
    return true;
}

int main() {
    int N, M, L, R, D;
    cin >> N >> M;
    REP(i, M) {
        cin >> L >> R >> D;
        G[L].push_back({R, D});
        G[R].push_back({L, -D});
    }

    FOR(i, 1, N + 1) {
        if (!used[i] && !dfs(i, 0)) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}