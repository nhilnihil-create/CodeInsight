/*


*/
#include <cstdio>
#include <cctype>
#include <algorithm>
#define MAXIN 300000
#define gc() (SS==TT&&(TT=(SS=IN)+fread(IN,1,MAXIN,stdin),SS==TT)?EOF:*SS++)
typedef long long LL;
const int N=2e5+5;

LL s[N];
char IN[MAXIN],*SS=IN,*TT=IN;

inline int read()
{
	int now=0;register char c=gc();
	for(;!isdigit(c);c=gc());
	for(;isdigit(c);now=now*10+c-48,c=gc());
	return now;
}

int main()
{
	const int n=read(); LL X=read(),ans=X*n;
	for(int i=1,a; i<=n; ++i) s[i]=s[i-1]+(a=read()), ans+=5ll*a;
	for(int k=1; k<n; ++k)
	{
		LL tmp=X*k;
		for(int i=n,j,t=1; i; i=j,++t)
		{
			j=std::max(i-k,0);
			tmp+=(s[i]-s[j])*std::max(5ll,t*2+1ll);
			if(tmp>ans) break;
		}
		ans=std::min(ans,tmp);
	}
	printf("%lld\n",ans+X*n);

	return 0;
}