#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;
const int MAXN = 16;

int n, a[MAXN][MAXN], b[MAXN+1];
ll f[1<<MAXN], g[1<<MAXN];

inline int count(int x)
{
	int res = 0;
	for(int i=0;i<n;++i)
		if(x&(1<<i)) ++res;
	return res;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	const int MAXS = 1<<n;
	for(int s=1;s<MAXS;s++)
	{
		int num = 0; g[s] = 0;
		for(int i=0;i<n;i++)
			if(s & (1<<i)) b[++num] = i;
		for(int i=1;i<num;i++)
			for(int j=i+1;j<=num;j++)
				g[s] += a[b[i]][b[j]];
	}
	for(int s=1;s<MAXS;s++){
		for(int t=s;t;t=(t-1)&s){
			f[s] = max(f[s], f[t] + g[s^t]);
		}
		f[s] = max(f[s], g[s]);
	}
	printf("%lld\n",f[MAXS-1]);
	return 0; 
}