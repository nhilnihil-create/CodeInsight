#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll flg,a[N],vis[N],n,m;
vector<ll> adj[N];
void dfs(ll node,ll clr){
    vis[node]=1;
    a[node]=clr;
    for(auto &v:adj[node]){
       if(vis[v]){
            if(a[v]==a[node]){
                cout<< (n*(n-1))/2 - m;
                exit(0);
            }
       }
       else{
            dfs(v,clr^1);
       }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,2);
    ll b=0;for(ll i=1;i<=n;i++)b+=(a[i]==2);
    cout<< b*(n-b) - m;
}

