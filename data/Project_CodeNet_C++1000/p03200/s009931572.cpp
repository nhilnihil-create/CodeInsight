#include<cstdio>
#include<cstring>
#define RI register int
#define CI const int&
using namespace std;
const int N=200005;
int n,c; long long ans; char s[N];
int main()
{
	RI i; scanf("%s",s+1); n=strlen(s+1);
	for (i=1;i<=n;++i) if (s[i]=='B') ++c; else ans+=c;
	return printf("%lld",ans),0;
}