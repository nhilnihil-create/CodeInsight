#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define p 1000000007
#define MAXN 100005
using namespace std;

int n, ans, sum[MAXN], a[MAXN], down[MAXN];

void init()
{
	sum[1]=sum[0]=1; down[0]=down[1]=1;
	for(int i=2; i<=n; i++) sum[i]=1LL*sum[p%i]*(p-p/i)%p;
	for(int i=2; i<=n; i++)
	{
		sum[i]=(sum[i-1]+sum[i])%p;
		down[i]=1LL*down[i-1]*i%p;
	}
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", &a[i]);
	init();
	for(int i=1; i<=n; i++) ans=(ans+1LL*(sum[i]+sum[n-i+1]-sum[1])*a[i]%p)%p;
	printf("%d\n", 1LL*ans*down[n]%p);
}