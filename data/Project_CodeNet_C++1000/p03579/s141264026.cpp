#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool visited[100005];
vector <int> graf[100005];
int col[100005];

void dfs(int v){
    visited[v] = 1;
    for(auto c : graf[v]){
        if(!visited[c]){
            col[c] = 1-col[v];
            dfs(c);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1);
    int bipartite = 1, cb = 0, cw = 0;
    for(int i=1; i<=n; i++){
        if(col[i]) cw++;
        else cb++;
        for(auto c : graf[i]){
            if(col[i] == col[c]) bipartite = 0;
        }
    }
    if(bipartite){
        cout << (ll)cw*cb-m;
    }
    else cout << (ll)n*(n-1)/2-m;
    return 0;
}
