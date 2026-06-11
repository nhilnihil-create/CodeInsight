#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300001],b[300001],s[300001];
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
    n=pow(2,read());
    for (register int i=0;i<n;++i)
	  a[i]=read();
    for (register int i=0;i<n;++i)
      for (register int j=i;j<=n;j=(j+1)|i)
      {
    	s[j]=max(s[j],a[i]+b[j]);
		b[j]=max(b[j],a[i]);
	  }
	for (register int i=1;i<n;++i)
	  s[i]=max(s[i],s[i-1]);
    for (register int i=1;i<n;++i)
	{
		write(s[i]);
		putchar('\n');
	}
    return 0;
}