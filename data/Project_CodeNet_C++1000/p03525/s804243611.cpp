#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define MAXN 50
int n,t[MAXN+5],ans=0;
bool u[25];
void dfs(int x)
{
    if(x==n)
    {
        int Min=1e8,last=0;
        for(int i=1;i<24;i++)
            if(u[i])
            {
                Min=min(Min,i-last);
                last=i;
            }
        Min=min(Min,24-last);
        ans=max(ans,Min);
        return;
    }
    if(!u[t[x]])
        {u[t[x]]=true;dfs(x+1);u[t[x]]=false;}
    if(t[x]!=(24-t[x])%24 && !u[24-t[x]])
        {u[24-t[x]]=true;dfs(x+1);u[24-t[x]]=false;}
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&t[i]);
    t[n++]=0;
    if(n>24) {printf("0\n");return 0;}
    dfs(0);
    printf("%d\n",ans);
    return 0;
}