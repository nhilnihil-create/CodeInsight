#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edge(N+1, vector<int>());
    vector<int> in(N+1, 0);
    for (int i = 0; i < N-1+M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        in[b]++;
    }
    int root;
    for (int i = 1; i <= N; i++){
        if (in[i] == 0) {
            root = i;
            break;
        }
    }
    
    vector<int> par(N+1);
    par[root] = 0;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int nxt : edge[now]) {
            if (in[nxt] == 1) {
                par[nxt] = now;
                q.push(nxt);
            }
            else in[nxt]--;
        }
    }
    for (int i = 1; i <= N; i++) cout << par[i] << endl;
    return 0;
}