#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int n,m;
vector<vector<int>> G;
vector<bool> seen(100010);

void dfs(int v){
    seen[v]=true;
    for(auto nv : G[v]){
        if(seen[nv]) continue;
        dfs(nv);
    }
}

int main(){
    cin>>n>>m;

    G.resize(n);
    rep(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        x--,y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int ans=0;

    rep(i,n){
        if(seen[i]) continue;
        dfs(i);
        ans++;
    }

    cout<<ans<<endl;
}


 