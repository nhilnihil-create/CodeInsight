#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,d,fl,fr,bo=1,fa[100010],dis[100010];
int find(int x)
{
    if(fa[x]!=x)
	{
        int t=fa[x];
        fa[x]=find(fa[x]);
        dis[x]+=dis[t];
    }
    return fa[x];
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
	{
        scanf("%d%d%d",&l,&r,&d);
        fl=find(l);
		fr=find(r);
        if(fl==fr&&dis[l]-dis[r]!=d)
        {
			bo=0;
		}
        if(fl!=fr)
		{
            fa[fl]=fr;
            dis[fl]=d+dis[r]-dis[l];
        }
    }
    if(bo)
	{
		cout<<"Yes";
	}
    else 
    {
		cout<<"No"; 
	}
    return 0;
} 