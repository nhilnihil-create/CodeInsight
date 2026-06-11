#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

using Graph = vector<vector<int>>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int>A(M);
    vector<int>B(M);

    Graph G(N+1);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        A[i] = a;
        B[i] = b;
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        vector<int>dist(N+1, -1);
        dist[1] = 0;
        queue<int> que;
        que.push(1);

        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto nv : G[v]) {
                if ((v == A[i] && nv == B[i]) || (v == B[i] && nv == A[i])) {
                    continue;
                }
                if (dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
        for (int j = 1; j <= N; j++) {
            if (dist[j] == -1) {
                cnt++;
                break;
            }
        }
    } 
    cout << cnt << endl;
}

