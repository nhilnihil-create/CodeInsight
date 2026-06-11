#include<bits/stdc++.h>
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
namespace io
{
	int F()
	{
		 int F=1,n=0;
		 char ch;
		 while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		 ch=='-'?F=0:n=ch-'0';
		 while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		 return F?n:-n;
	}
	long long G()
	{
		 long long F=1,n=0;
		 char ch;
		 while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		 ch=='-'?F=0:n=ch-'0';
		 while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		 return F?n:-n;
	}
}
int R(int l,int r)
{
	return (rand()<<15|rand())%(r-l+1)+l;
}
const int M=1000000007;
int a[111111];
int inv[111111];
int main()
{
	int n=io::F();
	inv[1]=1;
	for(register int i=2;i<=n;++i)inv[i]=((long long)(-M/i)*inv[M%i]%M+M)%M;
	for(register int i=1;i<=n;++i)a[i]=io::F();
	for(register int i=1;i<=n;++i)inv[i]=(inv[i]+inv[i-1])%M;
	int ans=0;
	for(register int i=1;i<=n;++i)ans=(ans+(long long)a[i]*(inv[i]+inv[n+1-i]-1))%M;
	for(register int i=1;i<=n;++i)ans=(long long)ans*i%M;
	printf("%d\n",ans);
	return 0;
}
