#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define R register
#define Maxn 100005

int main()
{
	R int n,sum=0;
	scanf("%d",&n);
	for (R int i=1;i<=n;++i)
	{
		sum += i;
		if(sum == n)
		{
			puts("Yes");
			printf("%d\n",i+1);
			R int j=1,cnt1=2;
			for (;j<=n;j+=cnt1,cnt1++)
			{
				printf("%d ",i);
				for (R int k=j-cnt1+2;k<=j;++k)printf("%d ",k);
				R int cnt2=cnt1-1;
				for (R int k=j+cnt2;k<=n;++cnt2,k+=cnt2)printf("%d ",k);
				puts("");
			}
			j=1,cnt1=2;
			printf("%d ",i);
			for (;j<=n;j+=cnt1,cnt1++)printf("%d ",j);
			return 0;
		}
	}
	puts("No");	
	return 0;
}