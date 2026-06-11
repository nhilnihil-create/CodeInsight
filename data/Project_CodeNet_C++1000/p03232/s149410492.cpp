#include<cstdio>
#include<vector>
#include<queue>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<stack>
#include<cstring>
using namespace std;

typedef long long LL;

const int INF = 2147483647;
const int maxn = 1000010;
const int crz = 1e9 + 7;

int n,a[maxn],inv[maxn];
int ans,fac;

inline LL getint()
{
	LL ret = 0,f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') 
		ret = ret * 10 + c - '0',c = getchar();
	return ret * f;
}

inline int qpow(int a,int b)
{
	int ret = 1;
	while (b)
	{
		if (b & 1) ret = 1ll * ret * a % crz;
		a = 1ll * a * a % crz;
		b >>= 1;
	}
	return ret;
}

inline int mod(int x)
{
	return x >= crz ? x - crz : x;
}

int main()
{
	#ifdef AMC
		freopen("AMC1.txt","r",stdin);
		// freopen("AMC2.txt","w",stdout);
	#endif
	fac = 1;
	
	n = getint();
	for (int i = 1; i <= n; i++)
		a[i] = getint() , fac = 1ll * fac * i % crz;
	
	for (int i = 1; i <= n; i++)
		inv[i] = mod(qpow(i,crz - 2) + inv[i - 1]);
	
	for (int i = 1; i <= n; i++)
	{
		int x = mod(mod(inv[i] + inv[n - i + 1]) - 1 + crz);
		ans = mod(ans + 1ll * x * a[i] % crz);
	}
	
	printf("%lld\n",1ll * ans * fac % crz);
	return 0;
}