#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<int,P> PP;
struct edge { int to; int cost; };
vector<int>G[200006];
int dis[200006];
void dfs(int now,int par){
    rep(i,G[now].size()){
        int e=G[now][i];
        if(par!=e){
            dis[e]=min(dis[now]+1,dis[e]);
            dfs(e,now);
        }
        
    }
    
}

signed main(){
    int n;cin>>n;
    rep(i,n-1){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    fill(dis,dis+n,inf);
    dis[0]=0;
    dfs(0,-1);
    
    int mx=0,mm;
    rep(i,n){
        if(mx<dis[i]){
            mx=dis[i];
            mm=i;
        }
        
    }
    fill(dis,dis+n,inf);
    dis[mm]=0;
    dfs(mm,-1);
    int di=0;
    rep(i,n)di=max(di,dis[i]);
    
    if(di%3!=1)puts("First");
    else puts("Second");
    
}