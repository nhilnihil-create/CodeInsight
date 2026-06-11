#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007
typedef vector<vector<int>> Graph;


vector<bool> seen;
void dfs(Graph &G,int v){
    seen[v]=true;
    for(auto nextv : G[v]){
        if(seen[nextv]) continue;
        dfs(G,nextv);
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    Graph G(N,vector<int>());
    seen.assign(N,false);
    rep(i,M){
        int x,y,z;
        cin >> x >> y >> z;
        x--;y--;
        G[x].push_back(y); // zが何であろうが関係ない
        G[y].push_back(x);
    }
    int cnt=0;
    for(int i=0;i<N;i++){
        if(seen[i]==false){
            if(G[i].size()!=0) dfs(G,i);
            seen[i]=true;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}