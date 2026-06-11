#include<bits/stdc++.h>
#define rg register
#define oo 0x7fffffff
#define ll long long
using namespace std;
inline int read()
{
	int out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		{
			fh=-1;
			jp=getchar();
		}
	while (jp>='0'&&jp<='9')
		{
			out=out*10+jp-'0';
			jp=getchar();
		}
	return out*fh;
}
const int MAXN=2e5+10;
int n,m;
vector<int> G[MAXN];
int del[MAXN]={0};
char buf[MAXN];
int Fa[MAXN],Fb[MAXN];
void Remove(int u)
{
	del[u]=1;
	for(rg unsigned ll int i=0;i<G[u].size();++i)
		{
			int v=G[u][i];
			if(del[v])
				continue;
			if(buf[u]=='A')
				Fa[v]--;
			else
				Fb[v]--;
			if(Fa[v]==0 || Fb[v]==0)
				Remove(v);
		}
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	scanf("%s",buf+1);
	for(rg int i=1;i<=m;++i)
		{
			int u=read(),v=read();
			G[u].push_back(v);
			G[v].push_back(u);
			if(buf[v]=='A')
				{
					Fa[u]++;	
				}
			else
				{
					Fb[u]++;
				}
			if(buf[u]=='A')
				{
					Fa[v]++;
				}
			else
				{
					Fb[v]++;
				}
		}
	for(rg int i=1;i<=n;++i)
		if(del[i]==0&&(Fa[i]==0||Fb[i]==0))
			Remove(i);
	for(rg int i=1;i<=n;++i)
		if(del[i]==0)
			{
				cout<<"Yes";
				return 0;
			}
	cout<<"No";
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
