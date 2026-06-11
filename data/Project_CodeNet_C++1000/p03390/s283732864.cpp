#include<bits/stdc++.h>
using namespace std;
long long t,a,b,c,ans;
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
	t=read();
	while (t--)
	{
		ans=0;
		a=read();b=read();
		if (a>b)
		  swap(a,b);
        c=sqrt(a*b);
        c-=(c*c==a*b);
        if (a==b||a==b+1)
		  ans=2*a-2;else
		if (c*(c+1)>=a*b)
		  ans=2*c-2;else
		  ans=2*c-1;
       	write(ans);
       	putchar('\n');
	}	
	return 0;
}