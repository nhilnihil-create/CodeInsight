#include<bits/stdc++.h>
using namespace std;
long long n,k,q,bx,cx,ans=INT_MAX,a[2001],s[2001],b[2001],c[2001];
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
    n=read();k=read();q=read();
    for (register int i=1;i<=n;++i)
	  s[i]=a[i]=read();
    sort(s+1,s+1+n);
    for (register int i=1;i<=n;++i)
    {
    	int l=1,r=1;
    	bx=0;
	    while (l<=n)
		{
        	cx=0;
 	        while (a[l]<s[i]&&l<=n)
			  ++l;
        	r=l;
    	    while (a[r]>=s[i]&&r<=n)
			  ++r;
    	    for (register int i=l;i<r&&i<=n;++i)
        	  c[++cx]=a[i];
    	    if (cx>=k)
			{
            	sort(c+1,c+1+cx);
        	    for (register int i=1;i<=cx-k+1;++i)
            	  b[++bx]=c[i];
        	}
        	l=r;
    	}
    	sort(b+1,b+1+bx);
    	if (bx>=q)
	 	  ans=min(ans,b[q]-b[1]);
	}
    write(ans);
    return 0;
}