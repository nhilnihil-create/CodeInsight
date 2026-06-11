#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void dfs(map<int, vi> G, vi &Q, int cur) {
    Q[cur] = true;

    for (int i = 0; i < G[cur].size(); i++) {
        if (Q[G[cur][i]]) continue;
        dfs(G, Q, G[cur][i]);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vi A(M), B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    int bridge_cnt = 0;
    // 落とす橋で全探索する
    rep(i, M) {

        map<int, vi> G;
        rep(j, M) {
            if (i == j) continue;
            G[A[j]].push_back(B[j]);
            G[B[j]].push_back(A[j]);
        }

        vi Q(N, false);

        int cnt = 0;
        for (int k = 0; k < N; k++) {
            if (!Q[k]) {
                dfs(G, Q, k);
                cnt++;
            }
        }
        if (cnt != 1) bridge_cnt++;
    }

    cout << bridge_cnt << endl;
}