#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define arr array

using namespace std;

const int e = 2e6 + 69;
const ll mod = 1e9 + 7;

ll a[e];
int n, m;
vector<int>adj[e];
bool vs[e];

void dfs(int u)
{
    vs[u] = false;
    for(auto j : adj[u]){
        if(vs[j]) dfs(j);
    }
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int dem =0;
    memset(vs, true, sizeof(vs));
    for(int i=1; i<=n; i++){
        if(vs[i] == true){
            dem ++;
            dfs(i);
        }
    }
    cout << dem;
}
