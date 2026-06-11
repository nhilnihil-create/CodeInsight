#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define arr array

using namespace std;

const int e = 2e6 + 69;
const ll mod = 1e9 + 7;

ll a[e];
int n;
vector<arr<int, 2>>adj[e];
ll col[e];
ll dep[e];

void dfs(int u, int par)
{
    for(auto j : adj[u]){
        if(j[0] == par) continue;
        dep[j[0]] = dep[u] + j[1];
        dfs(j[0], u);
    }
}

int main()
{
    cin >> n;
    for(int i=1; i<n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dfs(1, 1);
    cout << 0 <<"\n";
    //memset(col, 0, sizeof(col));
    for(int i=2; i<=n; i++){
        //cout << dep[i] <<"\n";
        if(dep[i]&1){
            cout << 1 <<"\n";
        }
        else{
            cout << 0 <<"\n";
        }
    }
}
