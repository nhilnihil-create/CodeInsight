#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int n;
struct edge{
    int to,cost;
};
vector<edge> g[100010];
vector<int> col(100010,-1);

void dfs(int v,int c){
    //cout << v << " " << c << endl;

    col[v] = c;
    rep(i,g[v].size()){
        if(col[g[v][i].to] == -1){
            if(g[v][i].cost % 2 == 0){
                dfs(g[v][i].to, c);
            }else{
                dfs(g[v][i].to, (c+1)%2);
            }
        }
    }
}

int main(){
    cin >> n;
    int u,v,w;
    rep(i,n-1){
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    rep(i,n){
        if(col[i] == -1){
            dfs(i,0);
        }
    }

    rep(i,n) cout << col[i] << endl;

    return 0;
}