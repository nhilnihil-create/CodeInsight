#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
int low[100005];
int cnt,dep[100005],pos[100005];
vector<int> g[100005];
int n,m;
void dfs(int ind,int lst){
    dep[ind]=dep[lst]+1;
    low[ind]=dep[ind];
    //low[ind]=pos[ind]=++cnt;
    for(int i=0;i<g[ind].size();i++){
        int now=g[ind][i];
        if(now==lst) continue;
        if(dep[now]){
            low[ind]=min(low[ind],dep[now]);
            continue;
        }
        dfs(now,ind);
        low[ind]=min(low[ind],low[now]);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,0);
    cnt=0;
    for(int i=1;i<=n;i++)
        if(dep[i]==low[i] && i!=1)
            cnt++;
    printf("%d\n",cnt);
    return 0;
}
/*
7 7
1 3
3 4
4 5
4 6
5 6
6 7
7 2
*/