#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long ll;

const int N=5e3+5;
const ll inf=1e15;

int n,a,b,p[N];
ll f[N][N];

int main() {
	scanf("%d%d%d",&n,&a,&b);
	fo(i,1,n) scanf("%d",&p[i]);
	fo(i,0,n) fo(j,0,n) f[i][j]=inf;f[0][0]=0;
	fo(i,1,n)
		fo(j,0,n)
			if (f[i-1][j]!=inf) 
				if (p[i]>j) {
					f[i][j]=min(f[i][j],f[i-1][j]+a);
					f[i][p[i]]=min(f[i][p[i]],f[i-1][j]);
				} else f[i][j]=min(f[i][j],f[i-1][j]+b);
	ll ans=inf;
	fo(i,0,n) ans=min(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}