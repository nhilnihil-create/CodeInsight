#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=100005;
int n,p[N],siz[N],fa[N];
LL d[N],d_[N];
map <LL,int> s;

bool cmp(int x,int y)
{
	return d[x]>d[y];
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%lld",&d[i]),p[i]=i,s[d[i]]=i;
	sort(p+1,p+1+n,cmp);
	rep(i,1,n-1)
	{
		++siz[p[i]];
		LL D=d[p[i]]-n+2*siz[p[i]];
		if(D>=d[p[i]] || !s.count(D)) {puts("-1"); return 0;}
		fa[p[i]]=s[D],siz[fa[p[i]]]+=siz[p[i]];
		d_[fa[p[i]]]+=d_[p[i]]+siz[p[i]];
	}
	if(d_[p[n]]!=d[p[n]]) puts("-1");
	else rep(i,1,n-1) printf("%d %d\n",p[i],fa[p[i]]);
	return 0;
}