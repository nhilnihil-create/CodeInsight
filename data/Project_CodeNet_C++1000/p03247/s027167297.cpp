#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=1005;
int n,pool[N],bin[40];
struct point{int x,y;} dat[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void dfs(int x,int y,int d=30)
{
	if(d<0) return;
	if(abs(x)>abs(y))
	{
		if(x>0) dfs(x-bin[d],y,d-1),putchar('R');
		else dfs(x+bin[d],y,d-1),putchar('L');
	}
	else
	{
		if(y>0) dfs(x,y-bin[d],d-1),putchar('U');
		else dfs(x,y+bin[d],d-1),putchar('D');
	}
}

void solve(int x,int y)
{
	if(!((x+y)&1)) dfs(x,y-1),putchar('U');
	else dfs(x,y);
	puts("");
}

int main()
{
	n=getint();
	rep(i,1,n) dat[i].x=getint(),dat[i].y=getint(),pool[i]=dat[i].x+dat[i].y;
	rep(i,2,n) if((pool[i]-pool[1])&1) return puts("-1"),0;
	rep(i,0,30) bin[i]=1<<i;
	printf("%d\n",31+(!(pool[1]&1)));
	rep(i,0,30) printf("%d ",bin[i]);
	if(!(pool[1]&1)) printf("1 ");
	puts("");
	rep(i,1,n) solve(dat[i].x,dat[i].y);
	return 0;
}