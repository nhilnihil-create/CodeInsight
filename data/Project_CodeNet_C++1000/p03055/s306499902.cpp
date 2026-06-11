#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e5+5;
vector<ll> adj[N];
ll node,dist;
void dfs(ll src,ll pr,ll d){
    if(d>=dist){
        node=src;
        dist=d;
    }
    for(auto &v:adj[src])if(v!=pr)dfs(v,src,d+1);
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    for(ll i=0,u,v;i<n-1;i++)cin>>u>>v,adj[u].push_back(v),adj[v].push_back(u);
    dfs(1,1,0);
    dist=0;
    dfs(node,node,0);

    if(dist%3==1)cout<<"Second";
    else cout<<"First";
}
