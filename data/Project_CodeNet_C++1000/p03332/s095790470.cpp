#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<bitset>
#include<cstdio>
#include<string>
#include<time.h>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
using namespace std;
const int N=4e5+10,M=998244353;
long long c[N],l[N];
int main()
{
	int n;
	long long a,b,k,an=0;
	scanf("%d%lld%lld%lld",&n,&a,&b,&k);
	l[1]=1;
	c[0]=1;
	c[1]=n;
	for(int i=2;i<=n;i++)
	{
		l[i]=(M-M/i)*l[M%i]%M;
		c[i]=c[i-1]*(n-i+1)%M*l[i]%M;
	}
	for(int i=0;i<=n;i++)
	{
		if((k-a*i)/b<0)
			break;
		if((k-a*i)%b==0&&(k-a*i)/b<=n)
			an=(an+c[i]*c[(k-a*i)/b]%M)%M;
	}
	printf("%lld",an);
}