#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
#define ll long long

vector<pair<int,int> > adj[N];
int color[N];

void bipartite(int s){
    queue<int> q;
    q.push(s);
    color[s]=1;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first;
            if(color[v]==0){
                if(adj[u][i].second%2==0){
                    color[v]=color[u];
                }
                else
                    color[v]=3-color[u];
                q.push(v);
            }
        }
    }

}

int main(){
    int T,i,j,n;

    cin>>n;
    memset(color,0,sizeof(color));
    for(i=1;i<=n-1;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));

    }
    bipartite(1);

    for(i=1;i<=n;i++){
        printf("%d\n",color[i]-1);
    }



return 0;
}
