#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int M = 1000001;
int n,m,k,a[M],d[M];
char c[M];
int main()
{
	scanf("\n%s",c+1);
	n=strlen(c+1);
	for(int i=1;i<=n;i++) a[i]=c[i]-'0';
	if(!a[1] || a[n]) 
	{
		printf("-1");
		return 0;
	}
	int m=n/2;
	for(int i=1;i<=m;i++) if(a[i]!=a[n-i]) 
	{
		printf("-1");
		return 0;
	}
	k=2;
	printf("1 2\n");
	for(int i=2;i<=m;i++)
	{
		printf("%d %d\n",i+1,k);
		if(a[i]) k=i+1;
	}
	for(int i=m+2;i<=n;i++) printf("%d %d\n",i,k);
}