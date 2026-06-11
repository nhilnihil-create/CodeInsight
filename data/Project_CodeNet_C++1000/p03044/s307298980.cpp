#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

struct E{
    int to,co;
    E(int to = 0,int co = 0):to(to),co(co){}
};
using graph = vector<vector<E>>;

int main(){
    int n;cin >> n;
    graph G(n+1);
    rep(i,n-1){
        int u,v,w;cin >> u >> v >> w;
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }

    queue<int> q;
    q.push(1);
    vector<int> label(n+1,-1);
    label[1] = 1;
    while(!q.empty()){
        int v = q.front();q.pop();
        for(E nv:G[v]){
            if(label[nv.to]!=-1) continue;
            if(nv.co%2 == 1) label[nv.to] = 1-label[v];
            else label[nv.to] = label[v];
            q.push(nv.to);
        }
    }

    rep(i,n) cout << label[i+1] << endl;



    
}