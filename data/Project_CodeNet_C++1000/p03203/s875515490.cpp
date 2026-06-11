#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
template<typename T>
inline void read(T& s)
{
    s=0;int f=1;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
    s*=f;
}
//set<int>mp[200005];
set<int>vis[200005];
int n,m;
int k;
int x[200005];
int y[200005];
int main()
{
	read(n);
	read(m);
	read(k);
	for(int i=0;i<k;i++)
	{
		read(x[i]);
		read(y[i]);
		vis[y[i]].insert(x[i]);
	}
	for(int i=1;i<=m;i++)
		vis[i].insert(n+1);
	int cnt=0;
	int ans=12345678;
	bool o=0;
	int nx=1,ny=1;
	int ste=0;
	while(1)
	{
		cnt++;
		if(o==0)
		{
			if(vis[ny].count(nx+1)==0)
			{
				nx++;
				ste=0;
			}
			else
			{
				ste++;
				if(ste>=2)
				{
					ans=min(ans,(cnt+1)/2);
					break;
				}
			}
		}
		else
		{
			auto fie=*vis[ny].upper_bound(nx);
			ans=min(ans,cnt/2+fie-nx-1+(1-ste));
			if(ny<m && vis[ny+1].count(nx)==0)
			{
				ny++;
				ste=0;
			}
			else
			{
				ste++;
				if(ste>=2)
				{
					ans=min(ans,cnt/2);
					break;
				}
			}
		}
		o^=1;
	}
	cout<<ans<<endl;
    return 0;
}