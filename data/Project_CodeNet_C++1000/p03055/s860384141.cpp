/*
考虑直径，要么直径减1，要么直径减2（除了只有两个点的情况）。 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=2E5+5;
int n,sizeE,head[maxn]; 
struct edge
{
	int to,next;
}E[maxn*2];
inline void add(int u,int v)
{
	E[++sizeE].to=v;
	E[sizeE].next=head[u];
	head[u]=sizeE;
}
int pos,ans;
void dfs(int u,int F,int d)
{
	if(d>ans)
		ans=d,pos=u;
	for(int i=head[u];i;i=E[i].next)
	{
		int v=E[i].to;
		if(v==F)
			continue;
		dfs(v,u,d+1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=2;i<=n;++i)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1,1,1);
	dfs(pos,pos,1);
	if((ans+1)%3==0)
		cout<<"Second"<<endl;
	else
		cout<<"First"<<endl;
	return 0;
}
