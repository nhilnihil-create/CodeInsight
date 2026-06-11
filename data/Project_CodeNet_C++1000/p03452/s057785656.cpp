#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int fa[N];
int dis[N];
int n,m,x,y,d;
void init()
{
    for(int i=1;i<=n;i++)
        fa[i]=i,dis[i]=0;
}
int find(int x)
{
    if(fa[x]==x)return x;
    int k=fa[x];
    fa[x]=find(fa[x]);
    dis[x]+=dis[k];
    return fa[x];
}
void merge(int x,int y)
{
	int xx=find(x),yy=find(y);
    fa[yy]=xx;
    dis[yy]=dis[x]+d-dis[y];
}
int main()
{
    cin>>n>>m;
    init();
    while(m--)
    {
        cin>>x>>y>>d;
        if(find(x)!=find(y))
        {
            merge(x,y);
        }
        else{
            if(dis[y]-dis[x]!=d)
        	{
        		puts("No");
        		return 0;
        	}
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}