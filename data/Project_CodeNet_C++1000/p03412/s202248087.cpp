#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],b[200001],c[200001];
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
long long find(long long k)
{
    int l=1,r=n+1;
    while (l<r)
	{
        int mid=(l+r)/2;
        if (c[mid]>=k)
		  r=mid;else
		  l=mid+1;
    }
    return l;
}
int main()
{
    n=read();
    for (register int i=1;i<=n;++i)
	  a[i]=read();
    for (register int i=1;i<=n;++i)
	  b[i]=read();
    long long ans=0;
    for (register int k=1;k<30;++k)
	{
        long long x=(1<<k)-1;
        for (register int i=1;i<=n;++i)
		  c[i]=b[i]&x;
        sort(c+1,c+1+n);
        long long s=0; 
        for (register int i=1;i<=n;++i)
          s+=n-find((1<<(k-1))-(a[i]&x))+1;
        for (register int i=1;i<=n;++i)
          s-=find((1<<k)+(1<<(k-1))-(a[i]&x))-find((1<<k)-(a[i]&x));
        if (s%2==1)
		  ans+=(1<<(k-1));
    }
    write(ans);
    return 0;
}