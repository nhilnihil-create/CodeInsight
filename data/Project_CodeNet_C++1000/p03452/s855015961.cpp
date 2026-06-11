#include <bits/stdc++.h>
#define INF 999999999
using namespace std;
int dist[100005],x,y,d,i,viz[100005],ok,n,m;
vector <pair<int,int>> G[100005];

void dfs(int node){
    viz[node] = 1;
    for(auto v: G[node]){
        int vecin = v.first;
        int d = v.second;
        if(vecin<node)
            d = -d;
        int new_dist = dist[node] + d;
        if(dist[vecin] != INF && dist[vecin] != new_dist)
            ok = 1;
        dist[vecin] = new_dist;
        if(viz[vecin] == 0)
            dfs(vecin);
    }
}

int main()
{
    cin>>n>>m;
    for(i=1;i<=100005;i++)
        dist[i]=INF;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>d;
        if(x>y){
            swap(x,y);
            d = -d;
        }
        G[x].push_back(make_pair(y,d));
        G[y].push_back(make_pair(x,d));
    }

    for(i=1;i<=n;i++){
        if(viz[i]==0){
            dist[i] = 0;
            dfs(i);
        }
        if(ok==1){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";

    return 0;
}
