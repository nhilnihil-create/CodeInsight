#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

vector<vector<int>> G;
int n;
int ans[200010];

void dfs(int v,int p=-1,int c=0){
    ans[v]=c;
    for(auto nv : G[v]){
        if(nv==p) continue;
        dfs(nv,v,1-c);
    }
} 

int main(){
    cin>>n;
    G.resize(3*n);
    int x=n;
    rep(i,n-1){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        if(w%2==1){
            G[u].push_back(v);
            G[v].push_back(u);
        }
        else{
            G[u].push_back(x);
            G[x].push_back(u);
            G[v].push_back(x);
            G[x].push_back(v);
            x++;
        }
    }

    //cout<<"test"<<endl;

    dfs(0);
    rep(i,n) cout<<ans[i]<<endl;

}