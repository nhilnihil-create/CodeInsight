#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n;
int lx[Maxn],rx[Maxn];
long long ans=0;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&lx[i],&rx[i]);
	sort(lx,lx+n+1);
	sort(rx,rx+n+1);
	for (int i=0;i<=n;i++)
		if (lx[n-i]>rx[i]) ans+=lx[n-i]-rx[i];
	printf("%lld\n",2*ans);
	return 0;
}
