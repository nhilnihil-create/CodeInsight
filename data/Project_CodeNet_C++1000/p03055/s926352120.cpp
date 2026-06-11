#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int D[200000];
vector <vector <int>> vex;

void dfs(int i, int p) {
    for(int r : vex[i])
        if(r != p) {
            D[r] = D[i] + 1;
            dfs(r, i);
        }
    return ;
}

int main() {
    int n; cin >> n;
    vex.resize(n);
    int u, v;
    
    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        u -= 1; v -= 1;
        vex[u].push_back(v);
        vex[v].push_back(u);
    }
    dfs(0, 0);
    int rx = 0;
    for(int i = 0; i < n; ++i)
        if(D[i] > D[rx]) rx = i;
    
    memset(D, 0, sizeof D);
    dfs(rx, rx);
    int mx = 0;
    for(int i = 0; i < n; ++i)
        mx = max(mx, D[i]);
    
    cout << (mx % 3 == 1 ? "Second" : "First");
    return 0;
}