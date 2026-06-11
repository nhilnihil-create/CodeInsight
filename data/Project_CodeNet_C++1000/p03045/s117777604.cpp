#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
typedef pair<int,int>pii;
const int mxN=1e5+10,M=1e9+7;
int n,m,ans,cnt;
int x,y,z;
vector<int>adj[mxN];
int vis[mxN];
bool comp(int a,int b){
    return sz(adj[a])>sz(adj[b]);
}
void bfs(int x){
    vis[x]=true;
    queue<int>fila;
    fila.push(x);
    while(!fila.empty()){
        int u=fila.front();
        fila.pop();
        //cout<<u<<"\n";
        for(int v:adj[u]){            
            if(!vis[v]){
                vis[v]=true;
                cnt++;
                fila.push(v);
            }
        }
    }
}
// LONG LONG CASE
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int>v;
    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        adj[x].pb(y);
        adj[y].pb(x);
    }    
    for(int i=1;i<=n;i++){
        v.pb(i);
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<n;i++){
        if(cnt>=n)break;
        if(!vis[v[i]])ans++;
        bfs(v[i]);

    }    
    cout<<ans;


}