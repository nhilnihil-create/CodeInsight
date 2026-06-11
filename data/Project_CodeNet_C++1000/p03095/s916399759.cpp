#include<cstdio>
#define RI register int
#define CI const int&
using namespace std;
const int N=100005,mod=1e9+7;
int n,c[N],ans; char s[N];
inline int quick_pow(int x,int p=mod-2,int mul=1)
{
	for (;p;p>>=1,x=1LL*x*x%mod) if (p&1) mul=1LL*mul*x%mod; return mul;
}
int main()
{
	RI i,j; for (scanf("%d%s",&n,s+1),ans=i=1;i<=n;++i)
	++c[s[i]-'a'],(ans+=1LL*ans*quick_pow(c[s[i]-'a'])%mod)%=mod;
	return printf("%d",ans-1),0;
}