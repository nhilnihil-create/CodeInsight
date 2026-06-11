#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e5 + 5;
int n, m, sol;
bool vis[NMAX];
vector<int> graf[NMAX];

void dfs(int x) {
    vis[x] = 1;
    for(int i = 0; i < (int)graf[x].size(); i++) {
        if(!vis[graf[x][i]]) {
            dfs(graf[x][i]);
        }
    }
}
int main() {
    
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
            sol++;
        }
    }
    cout << sol;
    return 0;
}