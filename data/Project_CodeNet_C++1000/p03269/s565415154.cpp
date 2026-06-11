#include<bits/stdc++.h>
struct edge{
	int x,y,co;
}e[125];
int n,l,m,cnt;
void ins(int a,int b,int c)
{
	e[++cnt].x=a;e[cnt].y=b;e[cnt].co=c;
}
int main()
{
	scanf("%d",&l);
	n=floor(log2(l))+1;
	for(int i=1;i<n;i++)
	{
		ins(i,i+1,1<<(i-1));
		ins(i,i+1,0);
	}
	int now=0;int fu=1<<(n-1);
	while(l>1)
	{
		if(l&1)
		{
			ins(now+1,n,fu);
			fu|=1<<now;
		}
		l>>=1;
		now++;
	}
	printf("%d %d\n",n,cnt);
	for(int i=1;i<=cnt;i++) printf("%d %d %d\n",e[i].x,e[i].y,e[i].co);
}