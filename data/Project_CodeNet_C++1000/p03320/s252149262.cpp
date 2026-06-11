#include<algorithm>
#include<cstdio>
#define LL long long
using namespace std;
int n,sl,fh;
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int calc(LL x) {int res=0; for(;x;res+=x%10,x/=10); return res;}
int main()
{
	n=rd();LL x=0,y=1;
	for(;n;--n)
	{
		x+=y;printf("%lld\n",x);
		if((x+y)*calc(x+10*y)>(x+10*y)*calc(x+y)) y*=10;
	}
	return 0;
}