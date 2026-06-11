#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[1000005];
ll l,r;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	l=2,r=3;
	for(int i=n;i>0;i--)
	{
		l=(l+a[i]-1)/a[i]*a[i];
		r=(r+a[i]-1)/a[i]*a[i];
		if(l==r)
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld %lld\n",l,r-1);
	return 0;
}