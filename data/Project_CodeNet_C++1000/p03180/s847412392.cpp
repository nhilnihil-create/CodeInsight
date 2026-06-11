#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxt=(1<<16)+10;
int n;
ll a[20][20];
ll val[maxt];
int p[maxt];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)if(i>>j&1)
		{
			p[i]++;
			for(int k=j+1;k<n;k++)if(i>>k&1)
			{
				val[i]+=a[j][k];
			}
		}
	}
	for(int i=0;i<(1<<n);i++)
	{
		if(p[i]<2)continue;
		for(int j=i;j;j=(j-1)&i)
		{
			if(j==i)continue;
			val[i]=max(val[i],val[j]+val[i-j]);
		}
	}
	printf("%lld\n",val[(1<<n)-1]);
	return 0;
}