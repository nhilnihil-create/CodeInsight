#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,m,q[N],ptr,use[N],deg[N][2],a[N];
string s;
vector<ll> adj[N];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>s;
    for(ll i=0;i<n;i++)a[i]=(s[i]=='A');
    for(ll i=0,u,v;i<m;i++){
        cin>>u>>v;
        u--;v--;
        adj[v].push_back(u);
        adj[u].push_back(v);
        deg[v][a[u]]++;
        deg[u][a[v]]++;
    }
    for(ll i=0;i<n;i++)if(deg[i][0]==0||deg[i][1]==0)use[i]=1,q[ptr++]=i;
    for(ll i=0;i<ptr;i++){
        ll u=q[i];
        for(auto &v:adj[u]){
            if(use[v])continue;
            deg[v][a[u]]--;
            if(deg[v][a[u]]==0)use[v]=1,q[ptr++]=v;
        }
    }
    cout<<(ptr==n?"No":"Yes");
}