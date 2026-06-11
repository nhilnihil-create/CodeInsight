#include<bits/stdc++.h>
#define inf 1ll<<62
using namespace std;

int n;
int a[300010];
int max1[300010],ans[300010];

int main()
{
	scanf("%d",&n);
	n=1<<n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j=(j+1)|i)
		{
			ans[j]=max(ans[j],max1[j]+a[i]);
			max1[j]=max(max1[j],a[i]); 
		}
	}
	for(int i=1;i<n;i++)
	{
		ans[i]=max(ans[i],ans[i-1]);
		printf("%d\n",ans[i]);
	}
}