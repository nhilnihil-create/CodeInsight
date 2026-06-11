#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int N;
vector<vector<int>> G;
vector<int> C, D;

int bfs() {
    int ret = 0, idx = 0;
    D[0] = C[idx++];

    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        auto q = Q.front(); Q.pop();
        for (auto g : G[q]) {
            if (D[g]) continue;
            D[g] = C[idx++];
            ret += D[g];
            Q.push(g);
        }
    }

    return ret;
}

int main() {
    cin >> N;
    G.resize(N); C.resize(N); D.resize(N);

    REP(i, 0, N - 1) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    REP(i, 0, N) cin >> C[i];
    sort(ALL(C), greater<int>());

    cout << bfs() << endl;
    for (auto d : D) cout << d << " ";
    cout << endl;

    return 0;
}