#include<bits/stdc++.h>
using namespace std;
#define maxn 100110
int n,a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	sort(a,a+n);
	int ans=a[0],ret=a[0]>a[n-1]/2?a[n-1]-a[0]:a[0];
	for(int i=1;i<n-1;++i)
	{
		int tmp=a[i]>a[n-1]/2?a[n-1]-a[i]:a[i];
		//printf("a[%d]=%d,tmp=%d\n",i,a[i],tmp);
		if(tmp>ret)
		{
			ret=tmp;
			ans=a[i];
		}
	}
	printf("%d %d\n",a[n-1],ans);
	return 0;
}