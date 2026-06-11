#include<cstdio>
#define RI register int
#define CI const int&
using namespace std;
const int N=105;
int n,tn,a[N],ans[N];
int main()
{
	RI i,j; for (scanf("%d",&n),i=1;i<=n;++i) scanf("%d",&a[i]);
	tn=n; while (n)
	{
		int pos=0; for (i=n;i;--i) if (a[i]==i) { pos=i; break; }
		if (!pos) return puts("-1"),0; ans[n]=pos;
		for (i=pos;i<n;++i) a[i]=a[i+1]; --n;
	}
	for (i=1;i<=tn;++i) printf("%d\n",ans[i]); return 0;
}