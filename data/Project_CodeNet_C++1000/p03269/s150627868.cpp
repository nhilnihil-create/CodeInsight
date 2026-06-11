#include<bits/stdc++.h>
#define ll long long
#define oo 0x7fffffff
using namespace std;
inline int read()
{
	int out=0,fh=1;
	char cc=getchar();
	while ((cc>'9'||cc<'0')&&cc!='-')
		cc=getchar();
	if (cc=='-')
		{
			fh=-1;
			cc=getchar();
		}
	while (cc>='0'&&cc<='9')
		{
			out=out*10+cc-'0';
			cc=getchar();
		}
	return out*fh;
}
int n;
int a[101],b[101],c[101],m=0;
void add(int u,int v,int w)
{
	++m;
	a[m]=u;
	b[m]=v;
	c[m]=w;
}
void Build(int x,int L)
{
	if(L<0)
		return;
	if(L==0)
		{
			if(x<n)
				add(x,n,0);
			return;
		}
	if(L==1)
		{
			add(x,n,0);
			add(x,n,1);	
			return;
		}
	if((L&1)==0)
		add(x,n,L);
	L=(L+1)/2;
	int y=x+1;
	add(x,y,0);
	add(x,y,L);
	--L;
	Build(y,L); 
}
void pr()
{
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;++i)
		printf("%d %d %d\n",a[i],b[i],c[i]);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int L=read();
	
	/*printf("%d %d\n",L,2*L-2);
	for(int i=1;i<L;++i)
		printf("%d %d %d\n",i,i+1,0);
	for(int i=2;i<=L;++i)
		printf("%d %d %d\n",1,i,i-1);*/
		
	n=20;
	Build(1,L-1);
	pr();
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
