#include <bits/stdc++.h>

using namespace std;
#define pb push_back
const int mn=2e5+5;

int n,m;
char s[mn];

int a[mn],b[mn];
bool vis[mn];
vector<int> g[mn];

int main() {
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1; i<=m; i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
        if (s[u]=='A') a[v]++;
        else b[v]++;
        if (s[v]=='A') a[u]++;
        else b[u]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++) {
        if (a[i]==0||b[i]==0) q.push(i),vis[i]=1;
    }
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(auto &i:g[u]) {
            if (s[u]=='A') {
                a[i]--;
                if (!vis[i]&&a[i]==0) q.push(i),vis[i]=1;
            }
            else {
                b[i]--;
                if (!vis[i]&&b[i]==0) q.push(i),vis[i]=1;
            }
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++)
        if (!vis[i]) ans=1;
    if (ans) puts("Yes");
    else puts("No");

    return 0;
}
