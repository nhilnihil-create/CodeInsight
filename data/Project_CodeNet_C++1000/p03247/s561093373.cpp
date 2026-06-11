#include<bits/stdc++.h>
using namespace std;
#define llong long long
int n;
int po[1010][2];
bool check(int x){return (x%2+2)%2;}
int m;
llong w[55];
int sym;
int gx,gy;
void solve(llong x,llong y,int cur)
{
	if(cur>m)return;
	llong dx=abs(x-gx),dy=abs(y-gy);
//	cout<<"cur: "<<cur<<" x: "<<x<<" y: "<<y<<" dx: "<<dx<<" dy: "<<dy<<endl;
	if(dx>=dy)
	{
		if(gx>=x)
		{
			putchar('R');
			solve(x+w[cur],y,cur+1);
			return;
		}
		else
		{
			putchar('L');
			solve(x-w[cur],y,cur+1);
			return;
		}
	}
	else
	{
		if(y<=gy)
		{
			putchar('U');
			solve(x,y+w[cur],cur+1);
			return;
		}
		else
		{
			putchar('D');
			solve(x,y-w[cur],cur+1);
			return;
		}
	}
}
int main()
{
	scanf("%d",&n);
	int ma=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&po[i][0],&po[i][1]);
		if(check(po[i][0]+po[i][1])!=check(po[1][0]+po[1][1]))
			puts("-1"),exit(0);
		ma=max(ma,abs(po[i][0]+po[i][1]));
	}
	sym=check(po[1][0]+po[1][1]);
	m=1;
	w[m]=1;
	while((1ll<<(m-1))<ma) m++;
	for(int i=1;i<=m;++i)w[i]=(1ll<<(m-i));
	if(!sym)m++,w[m]=1;
	printf("%d\n",m);
	for(int i=1;i<=m;++i)printf("%lld ",w[i]);puts("");
	for(int i=1;i<=n;++i)
		gx=po[i][0],gy=po[i][1],solve(0,0,1),puts("");
	return 0;
}
