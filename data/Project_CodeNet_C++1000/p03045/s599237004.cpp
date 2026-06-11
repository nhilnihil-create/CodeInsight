#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;

int main(void){
    int n,m;
    cin>>n>>m;
    Graph G(n);
    rep(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vector<int> dist(n,-1);
    queue<int> que;
    int count=0;
    rep(i,n){
        if(dist[i]!=-1) continue;
        dist[i]=count;
        que.push(i);
        while(!que.empty()){
            int v=que.front();
            que.pop();
            for(int nv:G[v]){
                if(dist[nv]!=-1) continue;
                dist[nv]=dist[v];
                que.push(nv);
            }
        }
        count++;
    }
    cout<<count<<endl;
    return 0;
}