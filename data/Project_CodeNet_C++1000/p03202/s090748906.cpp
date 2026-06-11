#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
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
int val[maxn],len[maxn];
int n,tp;
void push(int x)
{
	if(!tp||val[tp])val[++tp]=0,len[tp]=x;
	else len[tp]+=x;
}
void pop(int x)
{
	while(tp&&len[tp]<=x)x-=len[tp--];
	if(x)len[tp]-=x;
}
int inc(int limit)
{
	int x=0;
	while(tp&&val[tp]==limit-1)x+=len[tp--];
	if(!tp)return 0;
	if(len[tp]==1)++val[tp];
	else --len[tp++],val[tp]=val[tp-1]+1,len[tp]=1;
	if(x)val[++tp]=0,len[tp]=x;
	return 1;
}
int check(int mid)
{
	tp=0;
	for(int i=1;i<=n;i++)
		if(a[i]>a[i-1])push(a[i]-a[i-1]);
		else{
			pop(a[i-1]-a[i]);
			if(!inc(mid))return 0;
		}
	return 1;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	writeln(l);
	return 0;
}