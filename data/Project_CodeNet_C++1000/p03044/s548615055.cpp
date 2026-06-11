#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
vector<pair<int,int> > v[100005];
bool vis[100005];
int col[100005];
void dfs(int x,int c){
    col[x] = c;
    vis[x] = 1;
    for(pair<int,int> p:v[x]){
        int y = p.fi;
        int w = p.se;
        if(vis[y])continue;
        if(w%2)dfs(y,1-c);
        else dfs(y,c);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y,w;
        cin>>x>>y>>w;
        v[x].pb({y,w});
        v[y].pb({x,w});
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)cout<<col[i]<<endl;
}
