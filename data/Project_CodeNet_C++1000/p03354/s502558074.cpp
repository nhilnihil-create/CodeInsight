#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    vector<int> p(N);
    rep(i, N) {
        cin >> p[i];
        p[i]--;
    }
    vector<vector<int>> G(N);
    int x, y;
    rep(i, M) {
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vector<int> group(N);
    int tmp = 1;
    rep(i, N) {
        if (group[i]) continue;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int now = q.front(); q.pop();
            if (group[now]) {
                continue;
            }
            group[now] = tmp;
            rep(j, G[now].size()) q.push(G[now][j]);
        }
        tmp++;
    }
    int ans = 0;
    rep(i, N) {
        if (group[p[i]] == group[i]) ans++;
    }
    cout << ans << endl;
}
