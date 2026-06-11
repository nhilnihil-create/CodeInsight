#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int a[100005];
int b[100005];
int main()
{
	int i,n,sum=0;
	scanf("%d",&n);
	a[0]=0;
	a[n+1]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=abs(a[i]-a[i-1]);
		sum+=b[i];
	}
	b[n+1]=abs(a[n+1]-a[n]);
	sum+=b[n+1];
	for(i=1;i<=n;i++)
	{
		printf("%d\n",sum-b[i]-b[i+1]+abs(a[i+1]-a[i-1]));
	}
	return 0;
}