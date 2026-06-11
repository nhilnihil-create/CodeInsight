#include<bits/stdc++.h>
#include<iomanip>
#include<numeric>

using namespace std;
using ll = long long;
constexpr int mo = 1e9+7;
constexpr int  mod = mo;
constexpr int inf = 1<<30;
vector<int> E[100050];
vector<int> par(100050,-1);
map<int,int> c;
void bfs(int root){
    queue<int> q;
    q.push(root);
    par[root] = 0;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(auto e : E[cur]){
            c[e]--;
            if(c[e] == 0){
            par[e] = cur+1;
            q.push(e);
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int root;
    for(int i=0;i<n+m-1;++i){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        E[x].push_back(y);
        c[y]++;
    }
    for(int i=0;i<n;++i){
        if(c.count(i) == 0)root = i;
    }
    bfs(root);
    for(int i=0;i<n;++i){
        cout << par[i] << endl;
    }
    return 0;
}

