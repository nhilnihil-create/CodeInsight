#include<cstdio>
#include<cstring>
using namespace std;

const int N=200100,M=67110100,INF=2e9;
char s[N]; int n,pre[N],f[N],g[M];

inline int min(int x,int y) {return x<y?x:y;}
int main()
{
	scanf("%s",&s[1]); n=strlen(s+1);
	for (int i=1; i<=n; ++i) pre[i]=pre[i-1]^(1<<(s[i]-'a'));
	for (int i=1; i<=n; ++i) f[i]=i; for (int i=1; i<=M; ++i) g[i]=INF;
	for (int i=1; i<=n; ++i)
	{
		for (int j=0; j<=25; ++j) f[i]=min(f[i],g[(1<<j)^pre[i]]+1);
		f[i]=min(f[i],g[pre[i]]+1); g[pre[i]]=min(g[pre[i]],f[i]);
	}
	printf("%d",f[n]);
	return 0;
}