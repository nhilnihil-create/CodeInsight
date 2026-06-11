#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define maxn 200010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static char buf[20];
	int len=0;
	if(x<0)putchar('-'),x=-x;
	for(;x;x/=10)buf[len++]=x%10+'0';
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]);
}
inline void writesp(ll x){write(x); putchar(' ');}
inline void writeln(ll x){write(x); putchar('\n');}
int a[maxn];
ull sum[maxn];
int n,m;
int main()
{
	n=read(); m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sum[0]=0;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	ull ans=5*sum[n]+(ull)n*m;
	for(int i=1;i<n;i++){
		// printf("%d ***\n",i);
		ull cur=5*(sum[n]-sum[n-i])+(ull)m*i;
		for(int j=n-i,k=5;j>0;j-=i,k+=2){
			int l=std::max(1,j-i+1);
			// printf("%d %d : %d\n",l,j,k);
			cur+=(ull)k*(sum[j]-sum[l-1]);
		}
		// printf("%lld\n",cur);
		ans=std::min(ans,cur);
	}
	writeln(ans+(ull)n*m);
	return 0;
}