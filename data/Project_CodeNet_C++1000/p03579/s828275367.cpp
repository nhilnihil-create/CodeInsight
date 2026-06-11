#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1000005;
vector <int> g[N];
int n,m,c[N],ans,s1,s2,vis[N],flag,tot;

void dfs(int p) {
    ++tot;
    if(c[p]==1) s1++;
    if(c[p]==2) s2++;
    vis[p]=1;
    for(int i=0;i<g[p].size();i++) {
        int q=g[p][i];
        if(!vis[q]) {
            c[q]=3-c[p];
            dfs(q);
        }
        else if(c[p]==c[q]) flag=1;
    }
}

signed main() {
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++) {
        int t1,t2;
        scanf("%lld%lld",&t1,&t2);
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    for(int i=1;i<=n;i++) {
        if(vis[i]) continue;
        s1=s2=flag=tot=0;
        c[i]=1;
        dfs(i);
        if(flag==0) ans+=s1*s2;
        else ans+=tot*(tot-1)/2;
    }
    cout<<ans-m;
}
