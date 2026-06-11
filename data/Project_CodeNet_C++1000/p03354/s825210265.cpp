#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
tr1::unordered_map<int,int>mp;
vector<int>v[200000],res;
int n,m,p[200000];
bool vis[200000];
inline void read(int &x)
{
    char c=getchar();x=0;
    while(c>'9'||c<'0')c=getchar();
    while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+c-'0',c=getchar();
}
int x,y;
inline void dfs(int x,int f)
{
    vis[x]=1;
    res.push_back(x);
    for(int i=0;i<v[x].size();i++)
    {
        int y=v[x][i];
        if(y==f) continue;
        if(vis[y]) continue;
        dfs(y,x);
    }
}
int ans=0;
int main()
{
    read(n);read(m);
    for(int i=1;i<=n;i++) read(p[i]);
    for(int i=1;i<=m;i++)
    {
        read(x),read(y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            res.clear();
            mp.clear();
            dfs(i,0);
            for(int j=0;j<res.size();j++)
                mp[res[j]]=1;
            
            for(int j=0;j<res.size();j++)
            {
                if(mp[p[res[j]]])  ans++;
            }
        }
    }
    printf("%d",ans);
    //system("pause");
}