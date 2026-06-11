#include<cstdio>
#define RI register int
#define CI const int&
using namespace std;
const int N=200005;
int h,w,n,sx,sy,a,b,c,d; char s1[N],s2[N];
int main()
{
	RI i; scanf("%d%d%d%d%d%s%s",&h,&w,&n,&sx,&sy,s1+1,s2+1);
	for (i=n;i;--i)
	{
		switch (s2[i])
		{
			case 'U': if (b) --b; break;
			case 'D': if (a) --a; break;
			case 'L': if (d) --d; break;
			case 'R': if (c) --c; break;
		}
		switch (s1[i])
		{
			case 'U': ++a; break;
			case 'D': ++b; break;
			case 'L': ++c; break;
			case 'R': ++d; break;
		}
		if (a+b>=h||c+d>=w) return puts("NO"),0;
	}
	return puts(a<sx&&sx<=h-b&&c<sy&&sy<=w-d?"YES":"NO"),0;
}