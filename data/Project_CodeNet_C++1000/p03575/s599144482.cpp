#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> adj[50];
int t = 1, cnt = 0;
vector<int> disc(50,-1),low(50,-1);
bool visited[50];

void dfs(int i,int p){
    disc[i] = low[i] = t++;
    for(auto j : adj[i]){
        if(disc[j] == -1){
            dfs(j,i);
            low[i] = min(low[i],low[j]);
            if(low[j] > disc[i]){
                ++cnt;
            }
        }else if(j != p){
            low[i] = min(low[i],disc[j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(visited,false,sizeof(visited));
    dfs(0,-1);
    cout<<cnt<<"\n";
    return 0;
}


