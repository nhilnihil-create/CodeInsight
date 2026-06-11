#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <queue>

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define FOR(i, a, b) for(int i=a, loop=b; i<=loop; ++i)
#define REV(i, a, b) for(int i=a, loop=b; i>=loop; --i)
#define mize(a, b) a = min(a, b)
#define maxi(a, b) a = max(a, b)
#define shl(k) ((k) << 1)
using namespace std;

const int N = 1e5+5;
int n, m, deg[N], par[N];
vector<int> ke[N];

void dfs(int u)
{
    for(int v: ke[u]) if (--deg[v] == 0) par[v] = u;
    for(int v: ke[u]) if (par[v] == u) dfs(v);
}
int main()
{
    ios::sync_with_stdio(); cin.tie(0);

    cin >> n >> m;
    FOR(i ,1, m+n-1) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v); deg[v] += 1;
    }

    int root = 1;
    FOR(i, 2, n) if (deg[i] == 0) root = i;
    dfs(root);
    FOR(i, 1, n) cout << par[i] << '\n';
}
