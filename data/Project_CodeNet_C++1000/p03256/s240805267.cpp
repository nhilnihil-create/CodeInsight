#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
const int N=1e6;
int n,m,head[N+10],tot=0,f[N+10][2];
char s[N+10];
bool ok[N+10];
queue <int> q;
struct data {
    int next,num;
}edge[N+10];
void Add(int u,int v) {
    edge[++tot].next=head[u];
    edge[tot].num=v;
    head[u]=tot;
}
void Solve() {
    for (int i=1;i<=n;i++) {
        for (int j=head[i];j!=-1;j=edge[j].next) {
            int kx=edge[j].num;
            f[i][s[kx]-'A']++;
        }
    }
    for (int i=1;i<=n;i++)
        if (f[i][0]==0||f[i][1]==0) q.push(i);
        else ok[i]=1;
    while (!q.empty()) {
        int k=q.front();
        q.pop();
        for (int i=head[k];i!=-1;i=edge[i].next) {
            int kx=edge[i].num;
            if (!ok[kx]) continue;
            f[kx][s[k]-'A']--;
            if (!f[kx][s[k]-'A']) {
                ok[kx]=0;
                q.push(kx);
            }
        }
    }
    bool ans=0;
    for (int i=1;i<=n;i++) ans|=ok[i];
    if (ans) printf("Yes\n");
    else printf("No\n");
}
int main() {
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for (int i=1;i<=m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        Add(u,v);
        Add(v,u);
    }
    Solve();
    return 0;
}
