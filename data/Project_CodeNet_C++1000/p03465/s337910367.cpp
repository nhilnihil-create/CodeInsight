#include<bits/stdc++.h>
using namespace std;
#define MAXN 2005
int n;
int a[MAXN];
bitset<MAXN*MAXN>bts;
int ans[MAXN*MAXN],tot;
int main()
{
	scanf("%d",&n);
	int i;
	bts[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		bts|=bts<<a[i];
	}
	for(i=1;i<=MAXN*MAXN;i++)
	{
		if(bts[i])
		{
			tot++;
			ans[tot]=i;
		}
	}
	printf("%d",ans[(tot+1)>>1]);
	return 0;
}