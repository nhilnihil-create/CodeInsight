#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n,m,x,y;
    cin>>n>>m;
    
    vector<int> adj[n+2];
    int inorder[n+2];
    
    //Sorting using Kahn Algorithm..
    memset(inorder,0,sizeof(inorder));
    
    for(int i=1;i < n+m ;i++) {
        cin>>x>>y;
        adj[x].push_back(y); //DAG
        inorder[y]++; // taking account of incoming edges
    }
    
    queue<int> q;
    int parent[n+2]; // Result
    
    for(int i=1; i<=n;i++) {
        if(inorder[i] == 0) q.push(i); // root has no incoming edges so inorder[root ] = 0..
                                        // searching the root   
    }
    
    parent[q.front()] = 0; // parent[root] = 0
    
    // Sorting ...
    while(q.size() != 0) {
        int u = q.front();
        q.pop();
        
        for(int v : adj[u]) {
            if(--inorder[v] == 0) {
                q.push(v);
                parent[v] = u; // Next Vertex in DFS..
            }
        }
    }
    
    for(int i=1;i<=n;i++) cout<<parent[i]<<"\n";
    return 0;
}