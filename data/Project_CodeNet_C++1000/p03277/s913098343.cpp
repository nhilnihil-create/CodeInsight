#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt[202020],a[202020];
int n;
long long h;
bool jud(int mid)
{
	int now=100000,nsum=1;
	long long sum=0;
	memset(cnt,0,sizeof(cnt));
	cnt[now]++;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=mid)
		{
			nsum-=cnt[now];
			now--;
			cnt[now]++;
			nsum++;
		}
		else
		{
			now++;
			cnt[now]++;
			nsum+=cnt[now];
		}
		sum+=nsum-1;
	}
	return sum>=h;
}
int main()
{
	int l=1,r=1000000000,mid;
	scanf("%d",&n);
	h=((long long)(n+1)*n/2+1)/2;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while(l<r)
	{
		mid=(l+r)/2;
		if(jud(mid))
			l=mid+1;
		else
			r=mid;
	}
	printf("%d",l);
	return 0;
}