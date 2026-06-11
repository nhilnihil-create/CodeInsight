#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long LL;
const int M=2e5+5;
int a[M];

int main()
{
	int n;
	scanf("%d",&n);
	LL ans=-1;
	int f=1;
	a[0]=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[i-1]+1) f=0;
		if(a[i]==a[i-1]+1) ans++;
		else ans+=a[i];
	}
	if(!f) ans=-1;
	printf("%lld\n",ans);
	return 0;
}