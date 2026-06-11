#include<cstdio>
#include<algorithm>
int n,p=1000000000,opt=1;
long long ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x!=y) opt=0;
		ans=ans+x;
		if (x>y) p=std::min(p,y);
	}
	printf("%lld\n",opt?0:ans-p);
	return 0;
}