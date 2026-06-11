#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
struct node
{
	int next,to,v;
}e[600005];
int cnt;
int h[600005];
void add(int x,int y,int z)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
	e[cnt].v=z;
}
int c[100005];
void dfs(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		c[e[i].to]=e[i].v^c[x];
		dfs(e[i].to,x);
	}
}
int main(){
	int n,m;
	n=read();
	for(int i=1;i<n;i++)
	{
		int a,b,c;
		a=read();
		b=read();
		c=read();
		c%=2;
		add(a,b,c);
		add(b,a,c);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",c[i]);
//		cout<<c[i]<<endl;
	}
	return 0;
}