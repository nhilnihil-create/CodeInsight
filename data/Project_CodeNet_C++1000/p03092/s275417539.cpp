#include<map>
#include<set>
#include<ctime>
#include<queue>
#include<cmath>
#include<bitset>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mp(x,y) make_pair(x,y)
#define qmin(x,y) (x=min(x,y))
#define qmax(x,y) (x=max(x,y))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline int read(){
	int ans=0,fh=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') fh=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		ans=(ans<<1)+(ans<<3)+ch-'0',ch=getchar();
	return ans*fh;
}
const int maxn=5e3+100;
int n,A,B,p[maxn];
ll f[maxn][maxn],g[maxn];
int main(){
	//freopen("nh.in","r",stdin);
	//freopen("zhy.out","w",stdout);
	n=read(),A=read(),B=read();
	for(int i=1;i<=n;i++) p[i]=read();
	p[++n]=n+1;
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	for(int i=0;i<=n;i++){
		f[i][i]=0;
		for(int j=i+1;j<=n;j++)
			f[i][j]=f[i][j-1]+(p[j]>p[i]?A:B);
	}
	g[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			if(p[j]<p[i]) qmin(g[i],g[j]+f[j][i-1]);
	printf("%lld\n",g[n]);
	return 0;
}








