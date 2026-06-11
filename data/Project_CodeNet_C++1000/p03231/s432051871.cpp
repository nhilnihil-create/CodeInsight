#include<cstdio>
#include<map>
#define int long long
#define RI register int
#define CI const int&
using namespace std;
const int N=100005;
int n,m,l; char s[N],t[N]; map <int,char> res;
inline int gcd(CI n,CI m)
{
	return m?gcd(m,n%m):n;
}
signed main()
{
	RI i; scanf("%lld%lld%s%s",&n,&m,s+1,t+1); l=n*m/gcd(n,m);
	for (i=1;i<=n;++i) res[(i-1)*(l/n)+1]=s[i];
	for (i=1;i<=m;++i) if (res.count((i-1)*(l/m)+1)&&res[(i-1)*(l/m)+1]!=t[i])
	return puts("-1"),0; return printf("%lld",l),0;
}