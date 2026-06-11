#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int p=1e9+7;
int n,f[3005],g[3005];
char s[3005];
int Add(int x,int y){return (x+=y)>=p?x-p:x;}
int Sub(int x,int y){return (x-=y)<0?x+p:x;}
int main()
{
	scanf("%d%s",&n,s+1);
	g[1]=1;
	for(int i=2;i<=n;++i){
		for(int j=1;j<=i;++j){
			if(s[i-1]=='>')f[j]=Sub(g[i-1],g[j-1]);
			else f[j]=g[j-1];
		}
		for(int j=1;j<=i;++j)
			g[j]=Add(g[j-1],f[j]);
	}
	printf("%d\n",g[n]);
	return 0;
}