#include <bits/stdc++.h>
using namespace std;
#define N 2010

int n,K,Q,ans=2e9;
int a[N],b[N],c[N];

int main()
{
	scanf("%d%d%d",&n,&K,&Q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) {
		int tot=0;
		for (int j=1,nex;j<=n;j=nex+1) {
			nex=j; while (a[nex]>=a[i]) nex++;
			if (nex-j>=K) {
				for (int k=j;k<nex;k++) b[k]=a[k];
				sort(b+j,b+nex);
				for (int k=j;k<=nex-K;k++) c[++tot]=b[k];
			}
		}
		sort(c+1,c+tot+1);
		if (tot>=Q) ans=min(ans,c[Q]-a[i]);
	}
	printf("%d\n",ans);
	return 0;
}