#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
ll n,m,indeg[N],idx[N];
vector<ll> topo;
vector<ll> adj[N],rev_adj[N];
void toposort(){
    priority_queue<ll , vector<ll> , greater<ll> > pq;
    for(ll i=1;i<=n;i++)indeg[i]=rev_adj[i].size();
    for(ll i=1;i<=n;i++)if(!indeg[i])pq.push(i);
    while(!pq.empty()){
        ll node=pq.top();
        pq.pop();
        topo.push_back(node);
        for(auto &v:adj[node]){
            indeg[v]--;
            if(!indeg[v])pq.push(v);
        }
    }
    ll cur=0;
    for(auto &u:topo)idx[u]=++cur;
}
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    cin>>n>>m;
    for(ll i=1;i<=n-1+m;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
    toposort();
    for(ll i=1;i<=n;i++){
        ll par=0,cur=0;
        for(auto &v:rev_adj[i])if(idx[v]>cur)cur=idx[v],par=v;
        cout<<par<<"\n";
    }
}