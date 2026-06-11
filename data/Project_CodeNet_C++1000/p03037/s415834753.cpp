#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
struct node{
	int g,t;
}a[100005];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a[i].g,&a[i].t);
	}
	int sumstart=a[0].g;
	int sumover=a[0].t;
	for(int i=1;i<m;i++)
	{
		sumstart=max(a[i].g,sumstart);
		sumover=min(a[i].t,sumover);
	}
	int answer=sumover-sumstart+1;
	if(answer<0)
		answer=0;
	printf("%d\n",answer);
	return 0;
}