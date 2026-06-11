#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int N, M;
long long TBD = -1e18;

bool dfs(int s, vector<long long>& x, vector<map<int, int>>& adj) {
    for (auto itr = adj[s].begin(); itr != adj[s].end(); ++itr) {
        int r = (*itr).first, d = (*itr).second;
        if (x[r] != TBD) {
            if (x[r] != x[s] + d) return false;
            continue;
        }
        x[r] = x[s] + d;
        if (!dfs(r, x, adj)) return false;
    }
    return true;
}

int main() {
    cin >> N >> M;
    vector<long long> x(N + 1, TBD);
    vector<map<int, int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        adj[l][r] = d;
      	adj[r][l] = -d;
    }

    for (int i = 1; i <= N; i++) {
        if (x[i] != TBD) continue;
        x[i] = 0;
        bool flag = !dfs(i, x, adj);
        if (flag) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}