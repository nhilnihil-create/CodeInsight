#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;

int N, M;
vector<int> a,b;
vector<vector<bool>> to;
vector<bool> visited;

void dfs(int x){
    visited[x] = true;
    for (int i=0;i<N;i++){
        if (x==i) continue;
        if (to[x][i] && !visited[i]) dfs(i);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    a.resize(M),b.resize(M);
    to.resize(N,vector<bool>(N));
    for (int i=0;i<M;i++){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        to[a[i]][b[i]] = true;
        to[b[i]][a[i]] = true;
    }
    int ans = 0;
    visited.resize(N,false);
    for (int i=0;i<M;i++){
        to[a[i]][b[i]] = false;
        to[b[i]][a[i]] = false;
        for (int j=0;j<N;j++){
            visited[j] = false;
        }
        dfs(0);
        bool bridge = false;
        for (int j=0;j<N;j++) {
            if (!visited[j]) bridge = true;
        } 
        if (bridge) ans++;
        to[a[i]][b[i]] = true;
        to[b[i]][a[i]] = true;
    }
    cout << ans << "\n";
}