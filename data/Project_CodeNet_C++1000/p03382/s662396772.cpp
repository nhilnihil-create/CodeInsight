#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N],val;

int ab(int x)
{
	return x<0?-x:x;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int k=a[n];
	double v=(double)k/2;
	val=a[n];
	int ans=0;
	for(int i=1;i<=n;i++)
		if(abs((double)a[i]-v)<val)
			ans=a[i],val=abs((double)a[i]-v);
	printf("%d %d",a[n],ans);
}