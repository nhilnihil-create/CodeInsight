#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int n,m;
vector<P>g[100010];
int dist[100010];
bool visited[100010];
bool dfs(int v){
    visited[v]=1;
   for(auto u:g[v]){
       if(visited[u.first]){
           if(dist[u.first]!=dist[v]+u.second)return 0;
       }else{
           dist[u.first]=dist[v]+u.second;
           if(!dfs(u.first))return 0;
       }
   }

   return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    rep(i,m){
        int l,r,d;
        cin>>l>>r>>d;
        g[l].emplace_back(r,d);
        g[r].emplace_back(l,-d);
    }
    rep(i,n){
        if(visited[i+1])continue;
        if(!dfs(i+1))return cout<<"No"<<endl,0;
    }
    cout<<"Yes"<<endl;
    return 0;
}