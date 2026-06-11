#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x3f3f3f3f
#define maxn 2010
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
ll calc(ll p,ll q,ll len)
{
	if(len<=0)return 0;
	ll x=(q-p)/2;
	if(0<=x&&x<len)return (ll)(p+x)*(q-x);
	else return std::max((ll)p*q,(ll)(p+len-1)*(q-len+1));
}
// ll calc(ll p,ll q,ll len)
// {
// 	ll ret=calc_(p,q,len);
// 	printf("%lld %lld %lld : %lld\n",p,q,len,ret);
// 	return ret;
// }
ll getmax(int mid,int a,int b)
{
	if(a>b)std::swap(a,b);
	if(mid<a)return calc(1,mid,mid);
	else if(mid<b)return std::max(calc(1,mid,a-1),calc(a+1,mid-a+1,mid-a+1));
	else if(a-1<=mid-b+1)return std::max(std::max(calc(1,mid+1,a-1),calc(mid-b+3,b-1,b-1)),calc(a+1,mid-a+2,mid-a-b+2));
	else return std::max(std::max(calc(1,mid+1,mid-b+1),calc(a+1,mid-a+1,mid-a+1)),calc(mid-b+2,b-1,a+b-mid-2));
}
int main()
{
	int T=read();
	while(T--){
		int a=read(),b=read();
		ll l=0,r=a+b;
		while(l<r){
			ll mid=(l+r+1)>>1;
			if(getmax(mid,a,b)<(ll)a*b)l=mid;
			else r=mid-1;
		}
		writeln(l);
	}
	// while(1){
	// 	int a=read(),b=read(),mid=read();
	// 	writeln(getmax(mid,a,b));
	// }
	return 0;
}