#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX_N 100005

using namespace std;

int n,mx=0,md=0;
int a[MAX_N];

void read()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
}

void work()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=mx && min(a[i],mx-a[i])>min(md,mx-md)) md=a[i];
	}
	printf("%d %d\n",mx,md);
}

int main()
{
	read();
	work();
}
