#include<bits/stdc++.h>
#define int long long
using namespace std;
const double eps=1e-8;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
bool eq(double x,double y)
{
	return fabs(x-y)<eps;
}

signed main()
{
	int n=read(),ans=0;
	for (int l=1,r;l<=n;l=r+1)
	{
		int k=n/l;
		r=n/k;
		if (l<=n/k-1&&n/k-1<=r&&eq(n/k,double(n)/double(k))) ans+=n/k-1;
	}
	print(ans);

	return 0;
}