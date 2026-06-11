#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100005

vector<int> color(MAX_N, -1);
vector<int> adjlist[MAX_N];

bool check_bipartite() {
    queue<int> q;
    q.push(0);
    color[0] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u: adjlist[v]) {
            if (color[u] == -1) {
                q.push(u);
                color[u] = (color[v] + 1) % 2;
            } else {
                if (color[u] == color[v]) return false;
            }
        }
    }
    return true;
}

int main() {
    long long int N, M; cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        adjlist[a-1].push_back(b-1);
        adjlist[b-1].push_back(a-1);
    }
    if (check_bipartite()) {
        long long int black = 0;
        for (int i=0; i<N; i++) black += color[i];
        cout << black * (N-black) - M << endl;
    } else {
        cout << N * (N-1) / 2 - M << endl;
    }
}