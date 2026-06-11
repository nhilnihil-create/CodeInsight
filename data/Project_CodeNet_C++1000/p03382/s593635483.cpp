#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 105
using namespace std;
typedef unsigned long long ll;
int n,m;
int a[200005];
//ll c[maxn][maxn];
int myabs(int now)
{
	return now>0 ? now : -now;
}
int main()
{
//	freopen("a.txt","r",stdin);
//	c[0][0]=1;
//	for(int i=1;i<=30;i++)
//	{
//		c[i][0]=c[i][i]=1;
//		for(int j=1;j<=i-1;j++)
//		{
//			c[i][j]=c[i-1][j-1]+c[i-1][j];
//		}
//	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);

//	ll ans1=0;
//	int pos1,pos2;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//		{
//			if(c[a[i]][a[j]]>ans1)
//			{
//				pos1=a[i];
//				pos2=a[j];
//				ans1=c[a[i]][a[j]];
//			}
//		}

//	printf("guess 1\n");
//	printf("%d %d\n",pos1,pos2);

//	ll ans2=0;
	sort(a+1,a+1+n);
	int dis=a[n]+1,pos=1;
	for(int i=1;i<=n;i++)
	{
		if(myabs(a[n]-2*a[i])<dis)
		{
			pos=a[i];
			dis=myabs(a[n]-2*a[i]);
		}
	}

//	printf("guess 2\n");
	printf("%d %d\n",a[n],pos);
}
