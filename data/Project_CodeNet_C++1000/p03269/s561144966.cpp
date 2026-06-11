#include<bits/stdc++.h>
using namespace std;
long long l,t,n,s,c;
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
    l=read();
    t=l;
	while (t)
	{
		++n;
		t/=2;
	}
    s=__builtin_popcount(l)-1;
    write(n);putchar(' ');
	write(2*(n-1)+s);putchar('\n');
    c=1<<(n-1);
    for (register int i=n-2;i>=0;--i)
	{
        write(i+1);putchar(' ');
		write(i+2);putchar(' ');
		write(1<<i);putchar('\n');
        write(i+1);putchar(' ');
		write(i+2);putchar(' ');
		write(0);putchar('\n');
        if ((1<<i)&l)
		{
            write(i+1);putchar(' ');
			write(n);putchar(' ');
			write(c);putchar('\n');
            c+=1<<i;
        }
    }
    return 0;
}