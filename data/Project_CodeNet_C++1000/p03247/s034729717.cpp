#include<iostream>
#include<cstdio>
using namespace std;
int n,x[1010],y[1010],m,ma;
long long ln[101010];
int aabs(int x){ return x<0?-x:x;} 
void print(int X,int Y,int d)
{
	if(!d) return ;
	if(aabs(X)>aabs(Y))
	{
		if(X<0) print(X+ln[d],Y,d-1),putchar('L');
		else print(X-ln[d],Y,d-1),putchar('R');
	}
	else 
	{
		if(Y<0) print(X,Y+ln[d],d-1),putchar('D');
		else print(X,Y-ln[d],d-1),putchar('U');
	}
}
int main()
{
	scanf("%d",&n);
	int fl=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(fl==-1) fl=(x[i]+y[i])&1;
		else if(((x[i]+y[i])&1)!=fl) return puts("-1"),0;
	}
	if(fl)
	{
		for(int i=1;i<=n;i++) ma=max(ma,aabs(x[i])+aabs(y[i]));
		for(long long l=1;l-1<ma;l<<=1) ln[++m]=l;
		printf("%d\n",m);
		for(int i=1;i<=m;i++) printf("%d ",ln[i]);
		puts("");
		for(int i=1;i<=n;i++)
		print(x[i],y[i],m),puts("");
	}
	else
	{
		for(int i=1;i<=n;i++) ma=max(ma,aabs(x[i])+aabs(y[i]+1));
		for(long long l=1;l-1<ma;l<<=1) ln[++m]=l;
		printf("%d\n1 ",m+1);
		for(int i=1;i<=m;i++) printf("%d ",ln[i]);
		puts("");
		for(int i=1;i<=n;i++)
		printf("D"),print(x[i],y[i]+1,m),puts("");
	}
	return 0;
}
		
		