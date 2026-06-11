#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 2010
using namespace std;
bitset<N*N> dp;
ll n,a[N],sum=0; 
int main(){
	ll i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sum=(sum+1)/2;
	dp[0]=1;
	for(i=0;i<n;i++)
	{
		dp|=(dp<<a[i]);
	}
	for(i=sum;i<=sum*2;i++)
	{
		if(dp[i]==1)
		{
			printf("%lld\n",i);
			return 0;
		}
	}
	return 0;
}