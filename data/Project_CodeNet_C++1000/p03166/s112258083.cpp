#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int n,m;

int level[100005];
int dfs(int source){
    if(level[source]!=-1) return level[source];
    int res=0;
        for(int i=0;i<adj[source].size();i++){
            int v;
            v=dfs(adj[source][i]);
            res=max(res,v);
    }
    res++;
    level[source]=res;
    return res;
   
}
int main(){
   
     memset(level,-1,sizeof(level));
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> xoxo;
    for(int i=1;i<=n;i++){
        xoxo.push_back(dfs(i));
    }
    sort(xoxo.begin(),xoxo.end(),greater<int>());
    
    cout << xoxo[0]-1 << endl;
    
   
    
}