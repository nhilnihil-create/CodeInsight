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
int a[maxn],mark[maxn];
int id[maxn];
int n,k,q;
bool cmp(int x,int y){return a[x]<a[y];}
int check(int mx,int mn)
{
	for(int i=1;i<=n;i++)
		if(i<mn)mark[id[i]]=-1;
		else if(i>mx)mark[id[i]]=1;
		else mark[id[i]]=0;
	int last=0,cnt=0,tot=0;
	for(int i=1;i<=n;i++)
		if(mark[i]==-1){
			tot+=std::min(std::max((i-last-1)-(k-1),0),cnt);
			last=i; cnt=0;
		}
		else cnt+=(!mark[i]);
	tot+=std::min(std::max((n-last)-(k-1),0),cnt);
	return tot>=q;
}
int main()
{
	n=read(); k=read(); q=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		id[i]=i;
	std::sort(id+1,id+n+1,cmp);
	int ans=inf;
	for(int i=q;i<=n;i++){
		int l=0,r=i-q+1;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(i,mid))l=mid;
			else r=mid-1;
		}
		if(l)ans=std::min(ans,a[id[i]]-a[id[l]]);
	}
	writeln(ans);
	return 0;
}