#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;
const int maxn=200000+10;
vector<int> G[maxn];
bool vis[maxn];
int n;

int bfs_node(){
    memset(vis,0,sizeof vis);
    queue<int> Q;
    int u=0;
    Q.push(1);vis[1]=1;
    for(;!Q.empty();){
        u=Q.front();
        Q.pop();
        for(auto v: G[u])if(!vis[v]){
            vis[v]=true;
            Q.push(v);
        }
    }
    return u;
}

int bfs_d(int rt){
    memset(vis,0,sizeof vis);
    queue<pair<int,int> > Q;
    Q.push(make_pair(rt,1));
    vis[rt]=1;
    int u,d;
    for(;!Q.empty();){
        u=Q.front().first;
        d=Q.front().second;
        Q.pop();
        for(auto v: G[u])if(!vis[v]){
            vis[v]=true;
            Q.push(make_pair(v,d+1));
        }
    }
    return d;
}
int main(){
    scanf("%d",&n);
    for(int i=1,u,v;i<n;++i){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int hd=bfs_node();
    int de=bfs_d(hd);
    //cout<<hd<<" "<<de<<endl;
    if(de%3==2)puts("Second");
    else puts("First");
    return 0;
}