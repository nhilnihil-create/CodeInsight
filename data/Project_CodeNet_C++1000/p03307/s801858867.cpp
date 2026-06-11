#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
#define maxn 101000

int main()
{
	LL n;
	scanf("%lld",&n);
	if (n&1) printf("%lld\n",n*2);
	else printf("%lld\n",n);
	return 0;
}
