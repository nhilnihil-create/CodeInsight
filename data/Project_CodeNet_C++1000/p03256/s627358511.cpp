#include<bits/stdc++.h>
#define maxn 400005

using namespace std;
const int E=400;
char s[maxn];
int a[maxn],b[maxn],n,m,r,rr,d[maxn][2];
bool vis[maxn];
vector<int> h[maxn];

int main(){
    cin >> n >> m;
    scanf("%s",s);
    for (int i=1;i<=n;i++) a[i]=(s[i-1]=='A');
    for (int i=0;i<m;i++){
        int u,v; scanf("%d%d",&u,&v);
        h[u].push_back(v);
        h[v].push_back(u);
        d[u][a[v]]++; d[v][a[u]]++;
    }
    queue <int> q;
    for (int i=1;i<=n;i++) if (!d[i][0]||!d[i][1]) q.push(i);
    while (!q.empty()){
        int u=q.front(); q.pop();
        if (vis[u]) continue;
        vis[u]=true; rr++;
        for (int i=0;i<h[u].size();i++){
            int v=h[u][i];
            d[v][a[u]]--;
            if (!d[v][a[u]]) q.push(v);
        }
    }
    if (rr<n) puts("Yes"); else puts("No");
    return 0;
}
