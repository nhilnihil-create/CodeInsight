#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll limit=50;
ll n,m;
ll a[limit],b[limit];
bool graph[limit][limit];
bool visited[limit];

void dfs(ll v){
    visited[v]=true;
    for(ll v2=0;v2<n;v2++){
        if(graph[v][v2]==false) continue;
        if(visited[v2]==true) continue;
        dfs(v2);
    }
}

int main() {
    cin >> n >> m;
    for(ll i=0;i<m;i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        graph[a[i]][b[i]]=graph[b[i]][a[i]]=true;
    }
    ll ans=0;
    for(ll i=0;i<m;i++){
        graph[a[i]][b[i]]=graph[b[i]][a[i]]=false;
        for(ll j=0;j<n;j++) visited[j]=false;
        dfs(0);
        bool judge=false;
        for(ll j=0;j<n;j++){
            if(visited[j]==false) judge=true;
        }
        if(judge) ans++;
        graph[a[i]][b[i]]=graph[b[i]][a[i]]=true;
    }
    cout << ans << endl;
}
    