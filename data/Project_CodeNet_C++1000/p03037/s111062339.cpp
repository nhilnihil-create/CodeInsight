#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int f[100000];
int main()
{
	int n,i,x,y,m,h1,h2,h=0,k;
	scanf("%d%d",&n,&m);
	k=m;
	memset(f,0,sizeof(f));
	while(m--)
	{
		int min1=99999,min2=99999;
		scanf("%d%d",&x,&y);
		for(i=x;i<=y;i++)
		{
			f[i]++;
		}
		h1=min(min1,x);
		h2=max(min2,y);		
	}
	for(i=h1;i<=h2;i++)
	{
		if(f[i]==k)
		h++;
	}
	printf("%d",h);
	return 0;
	
}