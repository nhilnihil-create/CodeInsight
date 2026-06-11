#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long n,l,r,ans,a[N],s[N],c[4*N];
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
}
inline void add(long long x)
{
	for (;x<=2*N;x+=(x&(-x)))
	  ++c[x];
}
inline long long query(long long x)
{
	long long res=0;
	for (;x;x-=(x&(-x)))
	  res+=c[x];
	return res;
}
inline bool check(long long x)
{
	long long res=0;
	memset(c,0,sizeof(c));
	s[0]=0;
	for (register int i=1;i<=n;++i)
	  if (a[i]>=x)
        s[i]=s[i-1]+1;else
        s[i]=s[i-1]-1;
	for (register int i=0;i<=n;++i)
	{
		res+=query(s[i]+N);
		add(s[i]+N);
	}
	if (res>=1ll*n*(n+1)/4)
	  return true;
	return false;
}
int main()
{
	n=read();
	for (register int i=1;i<=n;++i)
	{
		a[i]=read();
		r=max(r,a[i]);
	}
	while (l<=r)
	{
		long long mid=(l+r)/2;
		if (check(mid))
		{
			l=mid+1;
		    ans=mid;
		}else
		  r=mid-1;
	}
	write(ans);
	return 0;
}