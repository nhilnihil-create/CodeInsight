#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset>
#include<complex>
using namespace std;
template<typename __T>
inline void read(__T &x)
{
    x=0;
    int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	{x=x*10+c-'0';c=getchar();}
    x*=f;
}
int n,m;
int fa[100005];
int d[100005];
int getfa(int x)
{
	if(fa[x]==x)	return x;
	int gg=fa[x];
	fa[x]=getfa(fa[x]);
	d[x]+=d[gg];
	return fa[x];
}
int unio(int a,int b,int dd)
{
	int x=getfa(a);
	int y=getfa(b);
	if(x==y)	return d[a]-d[b]==dd;
	fa[x]=y;
	d[x]=dd-d[a]+d[b];
	return 1;
}
int main()
{
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int a,b,c;
	while(m--)
	{
		read(a);
		read(b);
		read(c);
		int gg=unio(a,b,c);
	//	for(int i=1;i<=n;i++)	cout<<"G"<<i<<' '<<fa[i]<<" "<<d[i]<<endl;
		if(gg==0)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}