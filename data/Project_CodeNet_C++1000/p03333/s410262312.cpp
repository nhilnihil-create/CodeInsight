#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
long long l[101010],r[101010];
bool cmp(const int &x,const int &y)
{
	return x>y;
}
int main()
{
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&l[i],&r[i]);
	sort(l+1,l+1+n,cmp);
	sort(r+1,r+1+n);
	for(int i=2;i<=n;i++)
		l[i]+=l[i-1];
	for(int i=2;i<=n;i++)
		r[i]+=r[i-1];
	for(int i=1;i<=n;i++)
		ans=max(ans,l[i]*2-r[i]*2);
	for(int i=1;i<n;i++)
	{
		ans=max(ans,l[i]*2-r[i+1]*2);
		ans=max(ans,l[i+1]*2-r[i]*2);
	}
	printf("%lld",ans);
	return 0;
}