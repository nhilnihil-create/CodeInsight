#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
 
const ll oo = 1e18 + 7;
const ll mod = 1e9 + 7, maxn = (1e5) + 10;  
const long double PI = acos(-1);
vector<pii> adj[maxn];
vector<int> vis(maxn, -1);

void dfs(int v, int color){
    vis[v] = color;
    // cout << v << " " << color << endl;

    for (auto it: adj[v]){
        if (vis[it.ff] == -1) dfs(it.ff, (it.ss & 1) ^ (color));
    }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i=0; i<n-1;i++){
        int w, a, b;
        cin >>a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    dfs(1, 1);

    for (int i=1; i<=n; i++){
        cout << vis[i] << endl;
    }
    
    return 0;
}