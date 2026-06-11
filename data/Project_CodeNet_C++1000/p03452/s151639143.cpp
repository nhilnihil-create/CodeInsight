#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],b[1000001];
bool f=true;
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
inline int find(int x)
{
    if (a[x]==x)
      return x;
    int r=find(a[x]);
    b[x]=b[a[x]]+b[x];
    return a[x]=r;
}
inline bool dfs(int x,int y,int z)
{
    int fx=find(x);
    int fy=find(y);
    if (fx==fy)
      return z==b[y]-b[x];
    a[fy]=fx;
    b[fy]=b[x]+z-b[y];
    return true;
}
int main()
{
    n=read();m=read();
    for (register int i=1;i<=n;++i)
      a[i]=i;
    for (register int i=1;i<=m;++i)
    {
    	int x,y,z; 
		x=read();y=read();z=read();
    	if (f)
    	  f=dfs(x,y,z);
	}
    if (f)
      cout<<"Yes\n";else
      cout<<"No\n";
    return 0;
} 