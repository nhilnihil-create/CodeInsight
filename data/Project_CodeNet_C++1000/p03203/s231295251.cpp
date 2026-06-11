#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
const int N=200005;
struct coord
{
	int x,y;
	coord(int a,int b)
	{
		x=a;
		b=y;
	}
	coord(){}
};
coord c[N];
int h,w,n,r,o,d;
int ans;
bool cmp (coord a,coord b)
{
	return a.x<b.x;
}
int main()
{
	scanf("%d%d%d",&h,&w,&n);
	ans=h;
	for (int i=1;i<=n;i++)
		scanf("%d%d",&c[i].x,&c[i].y);
	sort(c+1,c+n+1,cmp);
	o=-1;
	for (int i=1;i<=n;i++)
	{
		o+=c[i].x-c[i-1].x+d;
		r=i;
		d=0;
		while (r<=n&&c[r].x==c[i].x)
		{
			if (c[r].x==1)
			{
				r++;
				continue;
			}
			if (c[r].y<=o)
				if (c[r].x-1<ans)
					ans=c[r].x-1;
			if (c[r].y==o+1)
				d=-1;
			r++;
		}
		i=r-1;
	}
	printf("%d\n",ans);
	return 0;
}