#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<sys/time.h>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int ri()
{
	register int x=0;register bool f=0;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();};
	return f?-x:x;
}
void wi(int x)
{
	if(x<0)	x=-x,putchar('-');
	if(x>9)	wi(x/10);
	putchar('0'+x%10);
}
const int N=2e5+7;
int a[N],b[N],aa[N],bb[N];
int main()
{
	int n=ri(),i,k,l1,l2,r1,r2,t=1,ans=0,sum;
	for(i=1;i<=n;i++)	a[i]=ri();
	for(i=1;i<=n;i++)	b[i]=ri();
	for(k=0;k<=28;k++,t*=2)
	{
		for(i=1;i<=n;i++)	aa[i]=a[i]%(2*t);
		for(i=1;i<=n;i++)	bb[i]=b[i]%(2*t);
		sort(bb+1,bb+1+n);sum=0;
		for(i=1;i<=n;i++)
		{
			l1=lower_bound(bb+1,bb+1+n,t-aa[i])-bb;
			r1=lower_bound(bb+1,bb+1+n,2*t-aa[i])-bb-1;
			l2=lower_bound(bb+1,bb+1+n,3*t-aa[i])-bb;
			r2=lower_bound(bb+1,bb+1+n,4*t-aa[i])-bb-1;
			sum+=r2-l2+1+r1-l1+1;
		}
		if(sum&1)	ans|=t;
	}
	wi(ans);putchar('\n');
	return 0;
}
