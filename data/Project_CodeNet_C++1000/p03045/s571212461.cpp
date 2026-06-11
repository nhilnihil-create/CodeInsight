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
int n,m;
int o[100005];
int oo(int x)
{
	return o[x]==x?x:o[x]=oo(o[x]);
}
int fa[100005];
int s[100005];//0相等，1不同
int find(int x)
{
	if(fa[x]==x)return x;
	int a=fa[x];
	fa[x]=find(fa[x]);
	s[x]=s[x]^s[a];
	return fa[x];
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)o[i]=i,fa[i]=i,s[i]=0;
	m=read();
	for(int i=1;i<=m;i++)
	{
		int c;
//		while((c=getchar())!='S'&&(c!='D'))c=getchar();
		int a,b;
		a=read();
		b=read();
		c=read();
		o[oo(a)]=oo(b);
		if(!(c&1))
		{
			if(find(a)==find(b))
			{
				if(s[a]!=s[b])
				{
					puts("0");
					return 0;
				}
			}
			else 
			{
				s[fa[b]]=s[b];
				fa[fa[b]]=a;
			}
		}
		else 
		{
			find(a);
			find(b);
//			cout<<a<<" "<<b<<' '<<fa[a]<<" "<<fa[b]<<" "<<s[a]<<" "<<s[b]<<endl;
			if(find(a)==find(b))
			{
				if(s[a]==s[b])
				{
					puts("0");
					return 0;
				}
			}
			else 
			{
				s[fa[b]]=s[b]^1;
				fa[fa[b]]=a;
			}
			find(a);
			find(b);
//			cout<<a<<" "<<b<<' '<<fa[a]<<" "<<fa[b]<<" "<<s[a]<<" "<<s[b]<<endl;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(oo(i)==i)
		{
			ans++;
		}
	}
//	long long res=1;
//	while(ans--)res*=2;
	printf("%d\n",ans);
	return 0;
}