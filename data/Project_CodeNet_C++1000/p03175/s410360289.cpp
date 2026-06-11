/*
    if you can't see the repay
    Why not just work step by step
    rubbish is relaxed
    to ljq
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod =  (int)1e9+7;
const int MAX_N = 100025;
int eid,p[MAX_N];
ll dp[MAX_N][2];
struct edge
{
    int v,next;
}e[MAX_N<<2];
void init()
{
    memset(p,-1,sizeof(p));
    eid = 0;
}
void add(int u,int v)
{
    e[eid].v = v;
    e[eid].next =p[u];
    p[u] = eid++;
}
void dfs(int u,int fa)
{
    ll x = 1, y = 1;
    if(e[p[u]].next==-1&&e[p[u]].v == fa)
    {
        dp[u][0] = dp[u][1] = 1;
        return ;
    }
    for(int i = p[u];i+1;i=e[i].next)
    {
        int v = e[i].v;
        if(v==fa) continue;
        dfs(v,u);
        x = (x*((dp[v][0] + dp[v][1])%mod))%mod;
        y = (y*(dp[v][0]))%mod;
    }
    dp[u][0] = x,dp[u][1] = y;
}
int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    int n,a,b;
    init();
    scanf("%d",&n);
    for(int i = 1;i<n;++i)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs(1,0);
    printf("%d\n",(dp[1][0]+dp[1][1])%mod);
    //fclose(stdin);
    //fclose(stdout);
    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}

