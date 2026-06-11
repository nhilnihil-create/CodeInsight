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
	int n;
	scanf("%d",&n);
	if (n&1)
	{
		printf("%d\n",(n/2)*(n/2+1));
	}else printf("%d\n",(n/2)*(n/2));
	return 0;
}
//135 246