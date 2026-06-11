#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& base) {
    for (T const& i : base) {
        out << i << ' ';
    }
    return out;
}
vector<int> S;
vector<bool> visited;
vector<list<int>> G;
void DFS(int x){
    visited[x] = true;
    for(int y : G[x]){
        if(!visited[y]) DFS(y);
    }
    S.push_back(x);
}
int main() {
    int N, M;
    cin >> N >> M;
    G.resize(N+1);
    visited.assign(N+1, false);
    for(int i = 0, x, y; i < M; ++i){
        cin >> x >> y;
        G[x].push_back(y);
    }
    for(int i = 1; i <= N; ++i){
        if(!visited[i]){
            DFS(i);
        }
    }
    int DP[N + 1];
    memset(DP, 0, sizeof DP);
    for(int i = 0; i < N; ++i){
        int node = S[i];
        for(int j : G[node]){
            DP[node] = max(DP[node], 1 + DP[j]);
        }
    }
    cout << *max_element(DP + 1, DP + N + 1) << endl;
}