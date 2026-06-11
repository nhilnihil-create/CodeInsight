#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int N;

void solve() {
    cin >> N;
    vector<P> G[N];
    for (int i = 0; i < N-1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; w %= 2;
        G[u].push_back(P(v, w));
        G[v].push_back(P(u, w));
    }
    vector<int> C(N, 0);
    queue<int> q;
    q.push(0);
    vector<bool> memo(N, false);
    memo[0] = true;
    while(!q.empty()) {
        int n = q.front(); q.pop();
        for (P p : G[n]) {
            if (memo[p.first]) continue;
            memo[p.first] = true;
            int parentC = C[n];
            C[p.first] = p.second == 0 ? parentC : (parentC + 1) % 2;
            q.push(p.first);
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << C[i] << endl;
    }
}

int main() {
    solve();
    return 0;
}
