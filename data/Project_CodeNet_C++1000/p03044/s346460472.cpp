#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;

using Graph = vector<vector<pair<int, int>>>;
Graph G;

vector<char> ans;

// v は現在見ている頂点, p は v の親
void dfs(int v, int p, char c) {
    // cout << "* " << v << endl;
    ans[v] = c;
    for (auto nv : G[v]) {
        // cout << "nv = " << nv.first << endl;
        if (ans[nv.first] != -1) continue;

        if (nv.second & 0x1) {
            dfs(nv.first, v, c == '0' ? '1' : '0');
        } else {
            dfs(nv.first, v, c);
        }
    }
}

int main() {
    int N;
    cin >> N;

    G.assign(N, vector<pair<int, int>>());
    ans.assign(N, -1);

    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;

        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    int root = 0;
    ans[root] = '0';
    dfs(root, -1, '0');

    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}
