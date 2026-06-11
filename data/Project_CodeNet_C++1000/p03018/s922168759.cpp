#include<cstdio>
#include<cstring>
#define RI register int
#define CI const int&
using namespace std;
const int N=200005;
int n,cur; char s[N]; long long ans;
int main()
{
	RI i; for (scanf("%s",s+1),n=strlen(s+1),i=1;i<n;++i)
	if (s[i]=='A') ++cur; else if (s[i]=='B')
	{ if (s[i+1]=='C') ans+=cur,++i; else cur=0; } else cur=0;
	return printf("%lld",ans),0;
}