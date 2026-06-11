#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int>to[10010];
int c[10010],a[10010],cnt,ans;

void dfs(int v, int p=-1){
    a[v]=c[cnt];
    for(int u:to[v]){
        if(u==p)continue;
        cnt++;
        dfs(u,v);
    }
}

void dfs2(int v, int p=-1){
    for(int u:to[v]){
        if(u==p)continue;
        ans+=min(a[v],a[u]);
        dfs2(u,v);
    }
}

int main(){
    int n;
    cin>>n;
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    rep(i,n)cin>>c[i];
    sort(c,c+n);
    reverse(c,c+n);
    dfs(0);
    dfs2(0);
    cout<<ans<<endl;
    rep(i,n)cout<<a[i]<<" ";
}