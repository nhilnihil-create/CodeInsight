#include<cstdio>
#define RI register int
#define CI const int&
using namespace std;
const int N=200005;
int n,a[N],stk[N],c[N],top,ans;
inline bool check(CI lim)
{
	if (lim==1)
	{
		for (RI i=2;i<=n;++i) if (a[i]<=a[i-1]) return 0; return 1; 
	}
	top=0; for (RI i=2;i<=n;++i) if (a[i]<=a[i-1])
	{
		int x=a[i]; while (top&&stk[top]>x) --top;
		while (top&&stk[top]==x&&c[top]==lim) --top,--x;
		if (!x) return 0; if (stk[top]==x) ++c[top]; else stk[++top]=x,c[top]=2;
	}
	return 1;
}
int main()
{
	RI i; for (scanf("%d",&n),i=1;i<=n;++i) scanf("%d",&a[i]);
	int l=1,r=n,mid; while (l<=r)
	if (check(mid=l+r>>1)) ans=mid,r=mid-1; else l=mid+1;
	return printf("%d",ans),0;
}