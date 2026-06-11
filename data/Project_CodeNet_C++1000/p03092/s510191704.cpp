#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
const int Q=5005;
ll f[Q][Q];
int p[Q];
int main()
{
	int n;
	ll a,b;
	scanf("%d%lld%lld",&n,&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++){
        f[i][p[i]]=998244353;
        for(int j=p[i];j;--j)
            f[i][j]=f[i-1][j]+a,f[i][p[i]]=min(f[i][p[i]],f[i-1][j]);
        for(int j=p[i]+1;j<=n;j++)
            f[i][j]=f[i-1][j]+b;
    }
    ll als=100000000000000000LL;
    for(int j=1;j<=n;j++)
        als=min(als,f[n][j]);
    printf("%lld\n",als);
	return 0;
}
