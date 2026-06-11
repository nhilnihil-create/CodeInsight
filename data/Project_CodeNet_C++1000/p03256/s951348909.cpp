#include <bits/stdc++.h>
using namespace std;

int n,m;
char ar[200005];
vector<int> G[200005];
bool V[200005];

void dfs(int node){
    int a=0,b=0;
    for(int i=0;i<G[node].size();i++){
        if(ar[G[node][i]]=='A')a++;
        if(ar[G[node][i]]=='B')b++;
    }
    if(a>=1&&b>=1)return;
    ar[node] = 0;
    for(int i=0;i<G[node].size();i++){
        if(ar[G[node][i]]!=0)dfs(G[node][i]);
    }
}

int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int node=1;node<=n;node++){
        if(ar[node]==0)continue;
        dfs(node);
    }
    for(int i=1;i<=n;i++){
        if(ar[i]!=0){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
