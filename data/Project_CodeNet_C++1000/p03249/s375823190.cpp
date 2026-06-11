#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
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
ll d[maxn];
std::map<ll,int>mp;
int id[maxn],fa[maxn],size[maxn],dep[maxn];
int n,rt;
bool cmp(int x,int y){return d[x]>d[y];}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		d[i]=read(),mp[d[i]]=i;
	for(int i=1;i<=n;i++)
		id[i]=i,size[i]=1;
	std::sort(id+1,id+n+1,cmp);
	for(int i=1;i<n;i++){
		fa[id[i]]=mp[d[id[i]]-(n-2*size[id[i]])];
		if(!fa[id[i]]||size[id[i]]*2>=n){
			puts("-1"); return 0;
		}
		size[fa[id[i]]]+=size[id[i]];
	}
	dep[id[n]]=0;
	for(int i=n-1;i;i--)
		dep[id[i]]=dep[fa[id[i]]]+1;
	ll sum=0;
	for(int i=1;i<=n;i++)
		sum+=dep[i];
	if(sum!=d[id[n]]){
		puts("-1"); return 0;
	}
	for(int i=1;i<n;i++)
		writesp(id[i]),writeln(fa[id[i]]);
	return 0;
}