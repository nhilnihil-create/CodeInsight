#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<sys/time.h>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int ri()
{
	register int x=0;register bool f=0;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();};
	return f?-x:x;
}
void wi(int x)
{
	if(x<0)	x=-x,putchar('-');
	if(x>9)	wi(x/10);
	putchar('0'+x%10);
}
const int N=300005;
/*int f[N],use[N],a[N],n,mn=1e9,mx=0;
inline void check()
{
	register int i,j,mx1=0,mx2=0;
	for(i=1;i<=n;i++)
	{
		f[i]=1;
		for(j=1;j<i;j++)
			if(a[j]<a[i])	f[i]=max(f[i],f[j]+1);
		mx1=max(mx1,f[i]);
	}
	for(i=1;i<=n;i++)
	{
		f[i]=1;
		for(j=1;j<i;j++)
			if(a[j]>a[i])	f[i]=max(f[i],f[j]+1);
		mx2=max(mx2,f[i]);
	}
	if(mx1+mx2<n/2+2||mx1+mx2>n+1)
	{
//		for(i=1;i<=n;i++)	printf("%d ",a[i]);
//		printf("mx1=%d mx2=%d sum=%d\n",mx1,mx2,mx1+mx2);
	}
	mn=min(mn,mx1+mx2);
	mx=max(mx,mx1+mx2);
}
void dfs(int x)
{
	if(x==n+1)	check();
	else
	{
		for(int i=1;i<=n;i++)	if(!use[i])
		{
			use[i]=1;a[x]=i;
			dfs(x+1);
			use[i]=0;
		}
	}
}*/
vector<int> v[N];
inline void gg()
{
	puts("-1");
	exit(0);
}
int main()
{
/*	n=ri();
	dfs(1);
	printf("mn=%d mx=%d\n",mn,mx);*/
	int n=ri(),a=ri(),b=ri(),j,i,d=n/a,now=n-a+1,tot=d;
	for(i=1;i<=d;i++,now-=a)
		for(j=1;j<=a;j++)
			v[i].push_back(now+j-1);
	if(n%a)
	{
		tot++;
		for(j=1;j<=n%a;j++)
			v[tot].push_back(j);
//		reverse(v[tot].begin(),v[tot].end());
	}
	if(b<tot||a+b>n+1)	gg();b-=tot;
/*	for(i=1;i<=tot;i++)
		for(j=0;j<v[i].size();j++)
			printf("i=%d %d\n",i,v[i][j]);*/
	for(i=tot;i>1;b-=v[i].size()-1,i--)
	{
		if(b<v[i].size()-1)	break;
		reverse(v[i].begin(),v[i].end());
	}
	if(b)
	{
		reverse(v[i].begin(),v[i].begin()+b+1);
	}
	for(i=1;i<=tot;i++)
		for(j=0;j<v[i].size();j++)
			printf("%d ",v[i][j]);
	puts("");
	return 0;
}
