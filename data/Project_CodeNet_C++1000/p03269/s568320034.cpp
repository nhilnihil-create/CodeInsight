#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define inf 2147483647
#define LL long long
using namespace std;
int n,m,a[100],b[100],ans = 1,x[100],y[100],z[100],cnt;
int main()
{
	scanf("%d", &n);
	while(n>=2)
	{
		if(n&1)
		{
			a[++m] = ans;
			b[m] = --n;
		}
		//if(n)
		//{
			x[++cnt] = ans;
			y[cnt] = ++ans;
			z[cnt] = n >>= 1;
			x[++cnt] = ans - 1;
			y[cnt] = ans;
			z[cnt] = 0;
		//}
			
	}
	printf("%d %d\n",ans,2*ans+m-2);
	for(int i=1;i<=m;++i)printf("%d %d %d\n",a[i],ans,b[i]);
	for(int i=1;i<=cnt;++i)printf("%d %d %d\n",x[i],y[i],z[i]);
	return 0;
}
