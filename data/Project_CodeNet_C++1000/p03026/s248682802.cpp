#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
#define MAXN 0x3f3f3f3f
vector<int>v[100005];
int n;
int c[100005];
int vis[100005];
bool cmp(int x,int y)
{
    return x>y;
}
int cnt=0;
int ans[100005];
/*void init(int a)
{
    cout<<a<<endl;
    if(a==n+1) return ;
    for(int i=0;i<v[a].size();i++)
    {
        if(vis[v[a][i]==0]) ans[v[a][i]]=c[cnt++];
        vis[v[a][i]]=1;
    }
    for(int i=0;i<v[a].size();i++)
    {
        init(v[a][i]);
    }
}*/
void init()
{
    queue<int>p;
    ans[1]=c[1];
    cnt=1;
    p.push(1);
    vis[1]=1;
    while(!p.empty())
    {
        int t=p.front();
        p.pop();
        for(int i=0;i<v[t].size();++i)
        {
            if(!vis[v[t][i]])
            {
                ans[v[t][i]]=c[++cnt];
                vis[v[t][i]]=1;
                p.push(v[t][i]);
            }
        }
    }

}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int maxx=0;
    int maxi;
    for(int i=1;i<=n;i++)
    {
        if(v[i].size()>maxx)
        {
            maxx=v[i].size();
            maxi=i;
        }
    }
    int sum=0;
    int maxmax=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
        if(c[i]>maxmax)
        {
            maxmax=c[i];
        }
        sum+=c[i];
    }
    sort(c+1,c+n+1,cmp);
    cout<<sum-maxmax<<endl;
    init();
    cout<<ans[1]<<' ';
    for(int i=2;i<=n;i++)
    {
        cout<<' '<<ans[i];
    }

}
