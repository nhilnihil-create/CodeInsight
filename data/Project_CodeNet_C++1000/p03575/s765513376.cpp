#include <iostream>
#include <cstring>
using namespace std;
bool g[60][60];
bool visited[60];
int N;

void dfs(int x){
    if(visited[x]) return;
    visited[x] = true;
    for(int i = 0; i < N; ++i){
        if(g[x][i]) dfs(i);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(g, false, sizeof(g));
    int M;
    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a][b] = g[b][a] = true;
    }

    int cnt = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(!g[i][j]) continue;
            memset(visited, false, sizeof(visited));
            g[i][j] = g[j][i] = false;
            dfs(0);
            bool flag = true;
            for(int k = 0; k < N; ++k) if(!visited[k]) flag = false;
            if(!flag) cnt++;
            g[i][j] = g[j][i] = true;
        }
    }
    cout << cnt/2 << endl;
    return 0;
}
//Saw the editorial