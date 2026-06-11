#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;

int n, m;
int x, y;
int p[maxn];
vector<int> e[maxn];
bool vis[maxn];
int ans;
set<int> pos;
void dfs(int u)
{
    vis[u] = true;
    pos.insert(u);
    for(int &x : e[u]) if(!vis[x]) dfs(x);
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
    }
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            dfs(i);
            for(int x : pos) if(pos.find(p[x]) != pos.end()) ans++;
            pos.clear();
        }
    }
    printf("%d\n", ans);
}
