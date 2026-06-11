#include<bits/stdc++.h>
using namespace std;
long long n,a,b;
inline int read()
{
   int sum=0,x=1;
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
inline void write(int x)
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
	n=read();a=read();b=read();
	if (a+b>n+1||a*b<n)
	{
		write(-1);
		return 0;
	}
	while (n)
	{
		long long s=min(a,n-(b-1));
		for (register long long i=n-(s-1);i<=n;++i)
		{
			write(i);
			putchar(' ');
		}
		n-=s;
		--b;
	}
	return 0;
}