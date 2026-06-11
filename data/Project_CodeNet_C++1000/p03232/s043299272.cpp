#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>

#define MOD 1000000007

inline int getnum()
{
	char c=getchar();
	while(!(c>='0' && c<='9'))
		c=getchar();
	int num=0;
	while(c>='0' && c<='9')
	{
		num*=10;num+=c-'0';
		c=getchar();
	}
	return num;
}

int m[505050];

int _factor(int num)
{
	int ans=1;
	for(register int i=2;i<=num;i++)
		ans=(long long)ans*i%MOD;
	return ans;
}

int inv[505050];
void initinv(int num)
{
	inv[1]=1;
	for(register int i=2;i<=num;i++)
		inv[i]=(long long)(MOD-MOD/i)*inv[MOD%i]%MOD;
}

unsigned s[505050];
int main()
{
	int N;scanf("%d",&N);
	for(register int i=1;i<=N;i++)
		m[i]=getnum();
	initinv(N);
	
	for(register int i=1;i<=N;i++)
		s[i]=(s[i-1]+inv[i])%MOD;
	unsigned ans=0;
	for(register int i=1;i<=N;i++)
		ans=(ans+(long long)(s[N-i+1]+s[i]-1)*m[i])%MOD;
	ans=(long long)ans*_factor(N)%MOD;
	printf("%u\n",ans);
	
	return 0;
}