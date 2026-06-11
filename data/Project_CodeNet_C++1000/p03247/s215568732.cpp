#include<bits/stdc++.h>
using namespace std;
long long n,xb,b[1001],c[1001],s[1001];
bool a[1001];
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
int main()
{
	n=read();
	for (register int i=1;i<=n;++i)
	{
		b[i]=read();c[i]=read();
		a[(b[i]+c[i])&1]=1;
	}
	if (a[0]&&a[1])
	{
		write(-1);
		return 0;
	}
	if (a[0])
	  s[++xb]=1;
	for (register int i=30;i>-1;--i)
	  s[++xb]=(1<<i);
	write(xb);putchar('\n');
	for (register int i=1;i<=xb;++i)
	{
		write(s[i]);
	    putchar(' ');
	}
	putchar('\n');
	for (register int i=1;i<=n;++i)
	{
		for (register int j=1;j<=xb;++j)
		{
			if (abs(b[i])>abs(c[i]))
			{
				if (b[i]>0)
				{
					b[i]-=s[j];
				    putchar('R');
				}else
				{
					b[i]+=s[j];
					putchar('L');
				}
			}else
			{
				if (c[i]>0)
				{
					c[i]-=s[j];
				    putchar('U');
				}else
				{
					c[i]+=s[j];
					putchar('D');
				}
			}
		}
		putchar('\n');
	}
	return 0;
}