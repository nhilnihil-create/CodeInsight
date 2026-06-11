#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

vector<vector<int>> G;
vector<int> color;

bool dfs(int v, int c){
    color[v] = c;
    for (int i = 0; i < G[v].size(); ++i) {
        int nv = G[v][i];
        if(color[nv] == c) return false;
        if(color[nv] == -1 && !dfs(nv, (c+1) % 2)) return false;
    }
    return true;
}

int main(){
    ll n, m;
    cin >> n >> m;
    G.assign(n, vector<int>());
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    color.assign(n, -1);

    if(dfs(0, 0)){
        ll white = 0;
        ll black = 0;
        for (int i = 0; i < n; ++i) {
            if(color[i]) white++;
            else black++;
        }
        cout << white * black - m << endl;
    }
    else cout << n * (n-1) / 2 - m << endl;
}