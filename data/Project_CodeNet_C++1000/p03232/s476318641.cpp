#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const int mod=1e9+7;
const int M=1e5+55;
const int N=1e5;

int bas[M];
int psum[M];
int n;
int w[M];
int ans;

int quickPow(int a,int b)
{
	int ret=1,bas=a;
	while(b!=0)
	{
		if(b&1)
			ret=(1ll*ret*bas)%mod;
		bas=(1ll*bas*bas)%mod;
		b>>=1;
	}
	return ret;
}

int getInv(int b)
{
	return quickPow(b,mod-2);
}

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	bas[1]=1;
	for(int i=2;i<=N;i++)
		bas[i]=(bas[i-1]+1ll*getInv(i))%mod;
	for(int i=1;i<=n;i++)
		psum[i]=(bas[i-1+1]+bas[n-i+1]-1)%mod;
}

void solve()
{
	ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+1ll*w[i]*psum[i])%mod;
	for(int i=1;i<=n;i++)
		ans=1ll*i*ans%mod;
	printf("%d\n",ans);
}

int main()
{
	init();
	solve();
	return 0;
}

/*

2
1 2

1:1.5*1=1.5
2:1.5*2=3
4.5*2=9

*/


