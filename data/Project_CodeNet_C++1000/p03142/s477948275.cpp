#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> e[n];
    int indeg[n]={};
    for(int i=0;i<n+m-1;i++){
        int s,t;
        cin>>s>>t;
        --s,--t;
        e[s].push_back(t);
        indeg[t]++;
    }
    int root;
    for(int i=0;i<n;i++){
        if(indeg[i]==0)root=i;
    }
    int ans[n];
    ans[root]=-1;
    queue<int> q;
    q.push(root);
    while(q.size()){
        int v=q.front();
        q.pop();
        for(int u:e[v]){
            indeg[u]--;
            if(indeg[u]==0){
                ans[u]=v;
                q.push(u);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]+1<<endl;
    }
}
