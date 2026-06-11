#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
vector<int> G[maxn];
int deg[maxn],vis[maxn],c[maxn],ans[maxn];
queue<int> q;
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;scanf("%d%d",&a,&b);
        G[a].push_back(b);G[b].push_back(a);
        deg[a]++;deg[b]++;
    }
    for(int i=1;i<=n;i++) scanf("%d",c+i);
    if(n==1){
        puts("0");
        printf("%d",c[1]);
        return 0;
    }
    sort(c+1,c+n+1);
    for(int i=1;i<=n;i++) if(deg[i]==1) q.push(i);
    int idx=0,tot=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        vis[x]=1;
        ans[x]=c[++idx];
        for(auto& u:G[x]){
            if(vis[u]) continue;
            deg[u]--;deg[x]--;
            if(deg[u]==1) q.push(u);
        }
    }
    for(int i=1;i<n;i++) tot+=c[i];
    printf("%d\n",tot);
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}
