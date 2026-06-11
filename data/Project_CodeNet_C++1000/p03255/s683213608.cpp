#include<iostream>
#include<cstdio>
#include<cstdlib>
#define ll unsigned long long
using namespace std;
const int N=200100;
ll A[N],ans=1e18;
int n,X;
int main()
{
	scanf("%d%d",&n,&X);
	for(int i=1;i<=n;i++) scanf("%llu",&A[i]),A[i]+=A[i-1];
	for(int K=1;K<=n;K++)
	{
		ll res=0,bs=3;
		for(int i=n;i>=1;i-=K,bs+=2)
			res+=(A[i]-A[max(0,i-K)])*bs;
		res+=(A[n]-A[max(0,n-K)])*2;
		ans=min(ans,res+1ll*(n+K)*X);
	}
	printf("%llu\n",ans);
}
