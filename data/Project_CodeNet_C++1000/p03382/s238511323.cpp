#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

const int N=100010;

int s[N],n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",s+i);
	std::nth_element(s+1,s+n,s+n+1);

	int ans=-1,maxw=-1;
	for(int i=1;i<n;i++)
	{
		int x=s[i]*2>s[n]?s[n]-s[i]:s[i];
		if(x>maxw)maxw=x,ans=s[i];
	}
	printf("%d %d\n",s[n],ans);
	return 0;
}
