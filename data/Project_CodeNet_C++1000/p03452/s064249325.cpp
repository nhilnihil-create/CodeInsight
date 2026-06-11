#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int type[maxn],dis[maxn];
int find(int a)
{
	if(type[a]==a) return a;
	else 
	{
		int pre=type[a];
		type[a]=find(type[a]);
		dis[a]+=dis[pre];
		return type[a];
	}
}
void fl()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
}
int main()
{
//	  fl();
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		type[i]=i;
	bool check=true;
	for(int i=1;i<=m;i++)
	{
		int l,r,d;
		cin>>l>>r>>d;
		if(!check) continue;
		int l_=find(l),r_=find(r);
		if(l_==r_)
		{
			if(dis[r]-dis[l]!=d) check=false;
		}
		else 
		{
			type[r_]=l_;
			dis[r_]=dis[l]+d-dis[r];
		}
	}
	if(check) puts("Yes");
	else puts("No");
	return 0;
}
