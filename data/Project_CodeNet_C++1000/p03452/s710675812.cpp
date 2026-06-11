#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int n,m;
int d[100010];

struct edge{int to,cost;};

vector<edge> G[100010];

void dfs(int pos1,int pos2){
    for(int i=0;i<G[pos1].size();i++){
        int next=G[pos1][i].to;
        if(d[next]!=INF || next==pos2)continue;
        d[next]=d[pos1]+G[pos1][i].cost;
        dfs(next,pos1);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    vector<int> l(m),r(m),c(m);

    for(int i=0;i<m;i++){
        cin>>l[i]>>r[i]>>c[i];
        l[i]--;r[i]--;
        G[l[i]].push_back(edge{r[i],c[i]});
        G[r[i]].push_back(edge{l[i],-c[i]});
    }
    
    for(int i=0;i<n;i++)d[i]=INF;

    for(int i=0;i<n;i++){
        if(d[i]!=INF)continue;
        d[i]=0;
        dfs(i,-1);
    }

    bool ans=true;

    for(int i=0;i<m;i++){
        if(d[r[i]]-d[l[i]]!=c[i])ans=false;
    }

    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}