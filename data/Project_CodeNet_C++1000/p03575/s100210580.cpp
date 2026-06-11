#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l1[51][51];
ll dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{-1,1},{-1,-1},{1,-1},{1,1}};
map<ll,ll>di;

vector<ll>adj[51];
ll visited[51];

void bfs(int s,int n)
{
    //for(int i=0;i<n;i++)visited[i]=0;
    queue<int>Q;
    Q.push(s);
    visited[s]=1;cout<<"->"<<s<<endl;///visited starting node.
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<adj[u].size();i++){

            if(visited[adj[u][i]]==0){
                int v=adj[u][i];
                visited[v]=1;
                cout<<"->"<<v<<endl;///visited nodes.
                Q.push(v);
            }
        }
    }
}


int main()
{
    ll n,k,m,a,b,s=0;
    cin>>n>>m;
    ll l1[n+1],l2[m+1];
    for(int i=1;i<=m;i++){
        cin>>a>>b;di[a]++;di[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //bfs(1,n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(di[j]==1){
                di[j]-=1;s++;
                for(int k=0;k<adj[j].size();k++){
                    di[adj[j][k]]-=1;
                }
            }
        }
    }
    cout<<s<<endl;
}
