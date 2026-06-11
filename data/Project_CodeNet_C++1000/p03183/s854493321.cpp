#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e4+5,M=2e4;
ll f[N];
struct dt {
	int w,s,v;
}d[N];

int main() {
	//freopen("1.in","r",stdin);
	//freopen("1.ans","w",stdout);
	
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d%d",&d[i].w,&d[i].s,&d[i].v);
	sort(d+1,d+n+1,[](const dt &lhs,const dt &rhs){return lhs.s+lhs.w<rhs.s+rhs.w;});
	for(int i=1;i<=n;++i) {
		for(int j=d[i].s;j>=0;--j) if(j+d[i].w<=M) f[j+d[i].w]=max(f[j+d[i].w],f[j]+d[i].v);
	}
	printf("%lld\n",*max_element(f,f+M+1));
	
	return 0;
}
