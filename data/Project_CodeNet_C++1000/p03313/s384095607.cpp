#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x3f3f3f3f
#define mod 998244353
#define maxn 300010
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
int a[maxn],mx1[maxn],mx2[maxn];
int n;
int main()
{
	n=read();
	for(int i=0;i<1<<n;i++)
		a[i]=read(),mx1[i]=a[i],mx2[i]=0;
	for(int k=1;k<1<<n;k<<=1)
		for(int j=0;j<1<<n;j+=(k<<1))
			for(int i=j;i<j+k;i++){
				int p=mx1[i],q=mx2[i],r=mx1[i+k],s=mx2[i+k];
				if(p>r){
					mx1[i+k]=p; mx2[i+k]=std::max(q,r);
				}
				else{
					mx1[i+k]=r; mx2[i+k]=std::max(p,s);
				}
			}
	int cur=0;
	for(int i=1;i<1<<n;i++){
		cur=std::max(cur,mx1[i]+mx2[i]);
		writeln(cur);
	}
	return 0;
}