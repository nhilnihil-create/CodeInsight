#include <cstdio>
#include <cctype>
#define reg register
#define int long long
using namespace std;
const int MaxN=200001;
template <class t> inline void rd(t &s)
{
	s=0;
	reg char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c))
		s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return;
}
int a[MaxN],f[MaxN],g[MaxN];
int n;
inline int getsum(int l,int r)
{
	return f[r]-f[l-1];
}
inline int getxor(int l,int r)
{
	return g[r]^g[l-1];
}
signed main(void)
{
	reg int ans=0;
	rd(n);
	for(int i=1;i<=n;++i)
	{
		rd(a[i]);f[i]=f[i-1]+a[i];g[i]=g[i-1]^a[i];
	}
	reg int l=1;
	for(int r=1;r<=n;++r)
	{
		while(getsum(l,r)!=getxor(l,r))
			++l;
		ans+=r-l+1;
	}
	printf("%lld",ans);
	return 0;
}