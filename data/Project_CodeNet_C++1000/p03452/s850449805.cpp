#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>

using namespace std;
typedef long long lint;

const int MAXN = 100100;
vector<pair<int, int> > G[MAXN];
lint depth[MAXN];
bool visited[MAXN];

bool dfs(int v, lint d) {
    depth[v] = d;
    visited[v] = true;
    for (const auto e : G[v]) {
        if (visited[e.first]) {
            if (depth[e.first] != d + e.second) {
                return false;
            }
        } else {
            if (!dfs(e.first, d + e.second)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        --l; --r;
        G[l].emplace_back(r, d);
        G[r].emplace_back(l, -d);
    }
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        if (!dfs(i, 0)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}