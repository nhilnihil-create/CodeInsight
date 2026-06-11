#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int N = 1e5 + 5;
vector<pair<int,int>> g[N];
LL d[N]; int x, y, w;

void dfs(int v, int p) {
    for(auto u : g[v]) {
        if(u.first != p) {
            d[u.first] = d[v] + u.second;
            dfs(u.first, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n; cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> x >> y >> w;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }    

    dfs(1, 0);

    for(int i = 1; i <= n; i++) cout << d[i] % 2 << '\n';
}