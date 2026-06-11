#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,m;
vector<int>to[100010],ver;
bool ok[100010];

void dfs(int v){
    ok[v]=true;
    for(int u:to[v]){
        if(ok[u])continue;
        dfs(u);
    }
    ver.push_back(v);
    return;
}

void Tsort(){
    rep(i,n)if(!ok[i])dfs(i);
    reverse(ver.begin(),ver.end());
    return;
}

int main(){
    cin>>n>>m;
    rep(i,n-1+m){
        int a,b;
        cin>>a>>b;
        to[a].push_back(b);
    }
    Tsort();
    vector<int>ans(n+1);
    rep(i,ver.size()){
        for(int u:to[ver[i]]){
            ans[u]=ver[i];
        }
    }
    for(int i=1; i<=n; ++i)cout<<ans[i]<<endl;
}