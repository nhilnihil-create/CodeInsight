//
// Created by Harshit on 21-08-2020.
//

#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e5+5;
int indegree[maxx];
bool dis[maxx];
void dfs(vector <vector <int >> &,vector <int> &,int );
int main(){
    int n,m;
    int u,v;
    cin>>n>>m;
    vector <int> visited(n+1,0);
    vector <vector <int>>  adjlist(n+1,vector <int> () );
    indegree[0]=0;
    visited[0]=0;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adjlist[u].push_back(v);
        indegree[v]++;
    }
    for(int i=1;i<n+1;i++){
        if(!dis[i] && indegree[i]==0)
            dfs(adjlist,visited,i);
    }
        int ans=0;
    for(int x:visited)
        ans=max(ans,x);
    cout<<ans<<endl;
}
void dfs(vector <vector <int >> &adjlist,vector <int> &visited,int sou){
    dis[sou]=true;
    for(auto it=adjlist[sou].begin();it!=adjlist[sou].end();it++){
        if(visited[*it]<visited[sou]+1){
            visited[*it]=visited[sou]+1;
        }
        indegree[*it]--;
        if(indegree[*it]==0 && !dis[*it])
            dfs(adjlist,visited,*it);
    }
}