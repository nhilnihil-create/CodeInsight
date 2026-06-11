#include<bits/stdc++.h>
#define Rep(i,a,b) for(register int i=(a);i<=(b);++i)
using namespace std;
template<typename T>inline void read(T&x)
{
	T f;register char ch;x=0;f=1;
	for(ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x*10)+(ch^48);
	x*=f;
}

const int MAXN=2e5+7;

static int n,a[MAXN],b[MAXN];

inline void init()
{
	read(n);
	Rep(i,1,n)read(a[i]),b[i]=a[i];
}

inline void solve()
{
	sort(b+1,b+n+1);
	b[0]=-1e9;
	int ps=lower_bound(b+1,b+n+1,b[n]/2)-b;
	if(b[n]-2*b[ps-1]>2*b[ps]-b[n])
	printf("%d %d\n",b[n],b[ps]);
	else printf("%d %d\n",b[n],b[ps-1]);
}

int main()
{
	init();
	solve();
	return 0;
}