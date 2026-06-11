#include<cstdio>

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(n==1&&k==1) return !printf("-1");
	if(k==0) for(int i=0;i<1<<n;i++) printf("%d %d ",i,i);
	else if(k<(1<<n))
	{
		printf("%d ",k);
		for(int i=(1<<n)-1;i>=0;i--) if(i!=k) printf("%d ",i);
		printf("%d ",k);
		for(int i=0;i<(1<<n);i++) if(i!=k) printf("%d ",i);
	}
	else printf("-1");
}