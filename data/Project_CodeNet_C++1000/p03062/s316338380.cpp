#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int n,a[100010];
int main()
{
	int i,j;
	ll sum=0,cnd=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			cnd++;
			a[i]=-a[i];
			sum+=a[i];
		}
		else 
		    sum+=a[i];
	}
	sort(a,a+n);
	if(cnd%2==0)
	{
		printf("%lld\n",sum);
	}
	else 
	{
		printf("%lld\n",sum-2*a[0]);
	}

	return 0;
}