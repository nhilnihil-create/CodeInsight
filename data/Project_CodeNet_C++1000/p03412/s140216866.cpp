#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>

#define _max(_a_,_b_) ((_a_)>(_b_)?(_a_):(_b_))

inline int getnum()
{
	register char c=0;
	while(!(c>='0' && c<='9'))
		c=getchar();
	register int a=0;
	while(c>='0' && c<='9')
		a=a*10+c-'0',c=getchar();
	return a;
}

int a[205050],b[205050];
#define GetLen(_arr,_l,_r) (std::lower_bound(&(_arr)[1],&(_arr)[N+1],_r)-std::lower_bound(&(_arr)[1],&(_arr)[N+1],_l))
int ta[205050],tb[205050];

int main()
{
	register int N=getnum(),mxv=0;
	for(register int i=1;i<=N;i++)
		a[i]=getnum(),mxv=_max(mxv,a[i]);
	for(register int i=1;i<=N;i++)
		b[i]=getnum(),mxv=_max(mxv,b[i]);
	register unsigned dig=1;
	while(mxv)
		dig++,mxv>>=1;
	
	int ans=0,pw2=1;
	while(dig--)
	{
		for(register int i=1;i<=N;i++)
			ta[i]=a[i]&((pw2<<1)-1),tb[i]=b[i]&((pw2<<1)-1);
		std::sort(&tb[1],&tb[N+1]);
		register bool sum=0;
		for(register int i=1;i<=N;i++)
			sum^=GetLen(tb,pw2-ta[i],(pw2<<1)-ta[i])&1,
			sum^=GetLen(tb,pw2+(pw2<<1)-ta[i],(pw2<<2)-ta[i])&1;
		ans|=pw2*sum,pw2<<=1;
	}
	printf("%d\n",ans);
	
	return 0;
}