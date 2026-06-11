#pragma GCC optime(3)
#pragma GCC optime(2)
#pragma GCC optime(1)
#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r=3,mn=INT_MAX,a[200001];
inline long long read()
{
    long long sum=0,x=1;
    char ch=getchar();
    while (ch<'0'||ch>'9')
	{
        if (ch=='-')
		  x=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9')
	{
        sum=sum*10+ch-'0';
        ch=getchar();
    }
    return sum*x;
}
inline void write(long long x)
{
    if (x<0)
	{
        putchar('-');
        x=-x;
    }
    if (x>9)
      write(x/10);
    putchar(x%10+'0');  
    return;
}
int main()
{
	n=read();
	for (register int i=1;i<=n;++i)
	{
		int x=read();
		a[i]=a[i-1]+x;
	}
	for (register int i=2;i<=n;++i)
	{
		while (l+1<i&&abs(a[i]-a[l]*2)>abs(a[i]-a[l+1]*2))
		  ++l;
		while (r+1<n&&abs(a[n]-a[r]-(a[r]-a[i]))>abs(a[n]-a[r+1]-(a[r+1]-a[i])))
		  ++r;
		long long b=max(a[l],max(a[i]-a[l],max(a[r]-a[i],a[n]-a[r])));
		long long c=min(a[l],min(a[i]-a[l],min(a[r]-a[i],a[n]-a[r])));
		mn=min(mn,b-c);
	}
	write(mn);
	return 0;
}