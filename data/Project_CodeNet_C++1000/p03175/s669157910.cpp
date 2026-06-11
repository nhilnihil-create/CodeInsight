#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const ll mod = 1e9 + 7;
const int mxn = 1e5 + 5;

int n;
vector<int> adj[mxn];
vector<ll> dpW(mxn,1), dpB(mxn,1);

void dfs(int u, int parent)
{
    for(int v : adj[u])
    {
        if(v == parent) continue;
        dfs(v,u);
        dpW[u] *= (dpW[v]+dpB[v]);
        dpB[u] *= dpW[v];
        dpW[u] %= mod;
        dpB[u] %= mod;
    }
}

int main()
{
  	FASTIO
    cin >> n;
    int x, y;
    for(int i=0; i<n-1; i++)
    {
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0,-1);
    cout << (dpW[0]+dpB[0])%mod << "\n";
    return 0;
}