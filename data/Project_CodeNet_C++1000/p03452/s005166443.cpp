#include <bits/stdc++.h>
using namespace std;
#define INF 1001001001001001

struct edge{int to; int cost;};
vector<edge> G[100000];
long long d[100000];

bool bfs(int i) {
    if(d[i] != INF) return true;

    d[i] = 0;
    queue<int> q;
    q.push(i);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(edge e : G[cur]) {
            if(d[e.to] == INF) {
                d[e.to] = d[cur] + e.cost;
                q.push(e.to);
            } else if(d[e.to] != d[cur] + e.cost) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; ++i) {
        int L,R,D;
        cin >> L >> R >> D;
        G[L-1].push_back({R-1, D});
        G[R-1].push_back({L-1, -D});
    }

    bool res = true;
    fill(d, d+N, INF);
    for(int i=0; i<N; ++i) {
        if(!bfs(i)) {
            res = false;
            break;
        }
    }
    if(res) cout << "Yes" << endl;
    else cout << "No" << endl;
}