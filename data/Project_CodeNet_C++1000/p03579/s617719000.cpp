#include<iostream>
#include<cstdio>
#include<vector> 
#include<cstring>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> list[maxn];
int vis[maxn];
int lose=0;
void bfs(int ne,int be,int re)
{
    if(!lose)
    {
        if(vis[ne]==-1)
            vis[ne]=re;
        else
            if(vis[ne]!=re)
            {
                lose=1;
                return;
            }
            else
                return;
        for(int i=0;i<list[ne].size();i++)
        {
            if(list[ne][i]!=be)
                bfs(list[ne][i],ne,!re);    
        }

    }

}
int main()
{
    long long m,n;
    scanf("%lld%lld",&m,&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        list[x].push_back(y);
        list[y].push_back(x);
    }
    memset(vis,-1,sizeof(vis));
    bfs(1,0,1);
    long long q=0,p=0;
    for(int i=1;i<=m;i++)
    {
        if(vis[i]==1)
            q++;
        else
            p++;
    }
    if(lose)
        printf("%lld\n",m*(m-1)/2-n);
    else
        printf("%lld\n",q*p-n);

    return 0;
}