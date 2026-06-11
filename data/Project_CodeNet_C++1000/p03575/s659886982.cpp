#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M;

void dfs(int n, vector<vector<int>> &Graph, vector<bool> &seen) {
    seen[n] = true;
    for (auto x : Graph[n]) {
        if (!seen[x]) dfs(x, Graph, seen);
    }
    return;
}

bool bridge(int n, vector<int> &a, vector<int> &b) {
    int cnt = 0;
    vector<bool> seen(N, false);
    vector<vector<int>> Graph(N);
    rep(i, M) {
        if (i == n) continue;
        Graph[a[i]].push_back(b[i]);
        Graph[b[i]].push_back(a[i]);
    }

    rep(i, N) if (!seen[i]) {
        ++cnt;
        dfs(i, Graph, seen);
    } 
    if (cnt == 1) return false;
    else return true;
}



int main() {
    cin >> N >> M;
    vector<int> a(M), b(M);
    rep(i, M) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }

    int ans = 0;
    rep(i, M) if (bridge(i, a, b)) ++ans;
    cout << ans << endl;
}
