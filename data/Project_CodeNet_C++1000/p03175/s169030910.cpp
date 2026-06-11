#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
vector<vector<int>> G;
int n;
ll dp_black[110000];
ll dp_white[110000];
bool done[110000];

void dfs(int now, int prev) {
    if (done[now]) return;
    done[now] = true;
    dp_black[now] = 1;
    dp_white[now] = 1;
    for (auto next: G[now]) {
        if (next == prev) continue;
        dfs(next, now);
        dp_white[now] *= dp_black[next] + dp_white[next];
        dp_white[now] %= MOD;
        dp_black[now] *= dp_white[next];
        dp_black[now] %= MOD;
    }
    return;
}
int main() {
    cin >> n;
    G.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    cout << (dp_black[0] + dp_white[0]) % MOD << endl;
    return 0;
}