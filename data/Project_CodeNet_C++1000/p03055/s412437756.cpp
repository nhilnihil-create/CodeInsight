#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=s;i<t;i++)
#define MAXNUM 222222
int dp[MAXNUM];
vector<int> e[MAXNUM];
int maxdep,maxpos;
void dfs(int now,int p,int d)
{
    if(d>maxdep)maxdep=d,maxpos=now;
    for(int k:e[now])if(k!=p)
        dfs(k,now,d+1);
}
int main()
{
    int n,a,b;scanf("%d",&n);
    rep(i,1,n)scanf("%d%d",&a,&b),e[a].push_back(b),e[b].push_back(a);
    dfs(1,1,0);
    maxdep=0,dfs(maxpos,0,0);maxdep++;
    dp[1]=0,dp[2]=1;
    for(int i=3;i<=maxdep;i++)
    {
        if(!dp[i-1]&&!dp[i-2])dp[i]=1;
        else dp[i]=0;
    }
    if(dp[maxdep])printf("Second");
    else printf("First");
}