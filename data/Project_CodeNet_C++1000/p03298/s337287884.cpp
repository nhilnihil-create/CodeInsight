#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#define ll long long
#define ull unsigned long long 
#define inf 0x3f3f3f3f
#define maxn 40000010
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
std::map<std::pair<ull,ull>,int>cnt;
char s[40];
int n;
int main()
{
	n=read();
	scanf("%s",s);
	for(int i=0;i<1<<n;i++){
		ull t1=0,t2=0;
		for(int j=0;j<n;j++)
			if(i&(1<<j))t1=t1*233+s[j];
			else t2=t2*2333+s[j];
		++cnt[std::make_pair(t1,t2)];
	}
	ll ans=0;
	for(int i=0;i<1<<n;i++){
		ull t1=0,t2=0;
		for(int j=0;j<n;j++)
			if(i&(1<<j))t1=t1*233+s[2*n-1-j];
			else t2=t2*2333+s[2*n-1-j];
		ans+=cnt[std::make_pair(t1,t2)];
	}
	writeln(ans);
	return 0;
}