#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pint;

signed main()
{
    int N,M; cin>>N>>M;
    vector<vector<int>> G(N);
    M+=N-1;
    vector<int> indeg(N);
    for(int i=0;i<M;i++){
        int a,b; cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        indeg[b]++;
    }
    queue<int> Q;
    for(int i=0;i<N;i++){
        if(indeg[i]==0){
            Q.push(i);
        }
    }
    vector<int> ans(N,-1);
    while(!Q.empty()){
        int v=Q.front();
        Q.pop();
        for(int u:G[v]){
            indeg[u]--;
            if(indeg[u]==0){
                ans[u]=v;
                Q.push(u);
            }
        }
    }
    for(int i=0;i<N;i++){
        cout<<ans[i]+1<<endl;
    }
}
