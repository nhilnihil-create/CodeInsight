#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
//#define MOD 1000000007
const int INF = 1LL<<30;

vector<vector<int>> G;
vector<int> ans;

void dfs(int cu,int pa,int c){
    ans[cu]=c;
    for(auto to : G[cu]){
        if(pa==to) continue;
        dfs(to,cu,1-c);
    }
}

int main() {
    int n;
    cin>>n;

    G.resize(3*n);
    ans.resize(3*n);
    int nxt=n;
    rep(i,n-1){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        if(w%2==1){
            G[u].push_back(v);
            G[v].push_back(u);
        }
        else{
            G[u].push_back(nxt);
            G[nxt].push_back(u);
            G[v].push_back(nxt);
            G[nxt].push_back(v);
            nxt++;
        }
    }

    dfs(0,-1,0);

    rep(i,n){
        cout<<ans[i]<<endl;
    }

}