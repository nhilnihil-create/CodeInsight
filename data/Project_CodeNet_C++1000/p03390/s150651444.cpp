#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#include<queue>
#include<algorithm>
//#include<iostream>
//#include<assert.h>
using namespace std;
 
int q;
#define LL long long
#define double long double
int main()
{
	scanf("%d",&q);
	while (q--)
	{
		int a,b; scanf("%d%d",&a,&b);
		if (a==1 && b==1) {puts("0"); continue;}
		if (a>b) a^=b^=a^=b; LL c=1ll*a*b-1,d=(LL)(sqrt((double)c));
		if (d*d>c) d--;
		LL ans=2*d-1;
		if (a==b) ans++;
		if (d==c/d) ans--;
		if (c/d==a && d!=a) ans--;
		printf("%lld\n",ans);
	}
	return 0;
}