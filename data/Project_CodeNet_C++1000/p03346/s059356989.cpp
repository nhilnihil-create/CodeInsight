#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int M=2e5+5;
int a[M],pos[M];

int main()
{
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	int pre=n+1,cnt=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(pos[i]>pre)
			cnt++;
		else
			cnt=1;
		pre=pos[i];
		ans=max(ans,cnt);
	}
	printf("%d\n",n-ans);
	return 0;
}