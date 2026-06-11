#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int n,m;
vector<vector<int>> g;
vector<vector<int>> f;
vector<bool> used;
vector<int> ans;
vector<int> node;

void dfs(int v){
    used[v]=true;
    for(int i:g[v]){
        if(!used[i])dfs(i);
    }
    node.push_back(v);
}

void dfs2(int v, int u){
    used[v]=true;
    ans[v]=u+1;
    for(int i:g[v]){
        if(!used[node[i]])dfs2(node[i],v);
    }
}

signed main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);  

    cin>>n>>m;
    g.resize(n); f.resize(n);
    ans.resize(n); node.resize(n);
    used=vector<bool>(n,0);
    rep(i,n+m-1){
        int a,b; cin>>a>>b;
        a--; b--;
        g[a].push_back(b);
        f[b].push_back(a);
    }

    rep(i,n)if(f[i].size()==0)dfs(i);
    reverse(all(node));

    vector<int> tmp(n);
    rep(i,n)tmp[node[i]]=i;
    rep(i,n){
        int l=tmp[i];
        rep(j,g[l].size())g[l][j]=tmp[g[l][j]];
        sort(all(g[l]));
    }

    fill(all(used),false);
    dfs2(node[0],-1);

    rep(i,n)cout<<ans[i]<<endl;
    return 0;

}