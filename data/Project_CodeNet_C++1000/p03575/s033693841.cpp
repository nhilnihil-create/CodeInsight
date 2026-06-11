#include <bits/stdc++.h>
using namespace std;
vector<set<int>>cycle(50,set<int>{});
vector<vector<int>>g(50,vector<int>(0));
int pushed[50];
int res = 0;

void dfs(int start, int leve,int i,vector<bool>visited){
    visited[i]=true;
    for(int j=0; j<g[i].size();j++){
        if(!(visited[g[i][j]])){
            dfs(start,leve+1, g[i][j],visited);
            

        }
        if(leve>1 && g[i][j]==start)
        {
            cycle[min(start,i)].insert(max(start,i));
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    for(int i=0;i<n;i++){
        vector<bool>visited(50,false);
        visited[i]=true;
        dfs(i,0,i,visited);
    }
    for(int i=0; i<n;i++){
        for(auto itr=cycle[i].begin(); itr!=cycle[i].end();itr++){
            m--;
        }
    }
    cout << m << endl;
    return 0;
}